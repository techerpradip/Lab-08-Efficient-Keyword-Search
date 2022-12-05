/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>

#include "hashFunctions.h"

using std::pair;
using std::runtime_error;
using std::vector;

template <typename K, typename V> HashTable<K, V>::HashTable() {
    this->load_factor = 0.75;
    this->size = 0;
    this->capacity = 4;
    this->hash_table = new LinearDictionary<K, V>[this->capacity];
}

template <typename K, typename V>
HashTable<K, V>::HashTable(float maxLoadFactor) {
    this->load_factor = maxLoadFactor;
    this->size = 0;
    this->capacity = 4;
    this->hash_table = new LinearDictionary<K, V>[this->capacity];
}

template <typename K, typename V> HashTable<K, V>::~HashTable() {
    delete[] this->hash_table;
}

template <typename K, typename V> int HashTable<K, V>::getSize() {
    return this->size;
}

template <typename K, typename V> bool HashTable<K, V>::isEmpty() {
    if (this->size == 0) {
        return true;
    } else {
        return false;
    }
}

template <typename K, typename V> void HashTable<K, V>::insert(K key, V value) {
    int index = hash(key, this->capacity);
    this->hash_table[index].insert(key, value);
    this->size ++;
    float current_loadFactor = ((float) this->size) / ((float) this->capacity);
    maintain_hash_load(current_loadFactor);
}

template <typename K, typename V> void HashTable<K, V>::update(K key, V value) {
    int index = hash(key, this->capacity);
    return this->hash_table[index].update(key, value);
}

template <typename K, typename V> V HashTable<K, V>::get(K key) {
    int index = hash(key, this->capacity);
    return this->hash_table[index].get(key);
}

template <typename K, typename V> bool HashTable<K, V>::contains(K key) {
    int index = hash(key, this->capacity);
    return this->hash_table[index].contains(key);
}

template <typename K, typename V> void HashTable<K, V>::remove(K key) {
    int index = hash(key, this->capacity);
    return this->hash_table[index].remove(key);
}

template <typename K, typename V> vector<K> HashTable<K, V>::getKeys() {
    vector<K> key_vector;
    for (int i = 0; i < this->capacity; i++) {
        vector<K> each_key_vector = this->hash_table[i].getKeys();
        key_vector.insert(key_vector.end(), each_key_vector.begin(),
                    each_key_vector.end());
    }
    return key_vector;
}

template <typename K, typename V>
vector<pair<K, V>> HashTable<K, V>::getItems() {
    vector<pair<K, V>> items_vector;
    for (int i=0; i < this->capacity; i++) {
        vector<pair<K, V>> each_items_vector = this->hash_table[i].getItems();
        items_vector.insert(items_vector.end(), each_items_vector.begin(),
                    each_items_vector.end());
    }
    return items_vector;
}

template <typename K, typename V> 
void HashTable<K, V>::maintain_hash_load(float current_load) {
    if (current_load > this->load_factor) {
        vector<pair<K, V>> items_vector = this->getItems();
        this->capacity *= 2;
        delete[] this->hash_table;
        this->size = 0;
        this->hash_table = new LinearDictionary<K, V>[this->capacity];
        for (int i=0; i < items_vector.size(); i++) {
            this->insert(items_vector[i].first, items_vector[i].second);
        }
    }
}
