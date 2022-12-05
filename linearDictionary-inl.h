/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <stdexcept>
#include<iostream>

template <typename K, typename V> LinearDictionary<K, V>::LinearDictionary() {
    return;
}

template <typename K, typename V> LinearDictionary<K, V>::~LinearDictionary() {
    return;
}

template <typename K, typename V> int LinearDictionary<K, V>::getSize() {
    return this->dictionary_vector.size();
}

template <typename K, typename V> bool LinearDictionary<K, V>::isEmpty() {
    if (this->dictionary_vector.size() == 0) {
        return true;
    } else {
        return false;
    }
}

template <typename K, typename V>
void LinearDictionary<K, V>::insert(K key, V value) {
    if (this->contains(key)) {
        throw std::runtime_error("Key already exists!");
    }
    pair<K, V> key_value(key, value);
    this->dictionary_vector.push_back(key_value);
}

template <typename K, typename V>
void LinearDictionary<K, V>::update(K key, V value) {
    for (int i = 0; i < this->dictionary_vector.size(); i++){
        if (this->dictionary_vector[i].first == key) {
            this->dictionary_vector[i].second = value;
            return;
        }
    }
    throw std::runtime_error("Key doesn't exist!");
}

template <typename K, typename V> V LinearDictionary<K, V>::get(K key) {
    for (int i = 0; i < this->dictionary_vector.size(); i++){
        if (this->dictionary_vector[i].first == key) {
            return this->dictionary_vector[i].second;
        }
    }
    throw std::runtime_error("Key doesn't exist!");
}

template <typename K, typename V> bool LinearDictionary<K, V>::contains(K key) {
    for (int i = 0; i < this->dictionary_vector.size(); i++){
        if (this->dictionary_vector[i].first == key) {
            return true;
        }
    }
    return false;
}

template <typename K, typename V> void LinearDictionary<K, V>::remove(K key) {
    for (int i = 0; i < this->dictionary_vector.size(); i++){
        if (this->dictionary_vector[i].first == key) {
            this->dictionary_vector.erase(this->dictionary_vector.begin() + i, 
                     this->dictionary_vector.begin() + i + 1);
            return;
        }
    }
    throw std::runtime_error("Key doesn't exist!");
}

template <typename K, typename V> vector<K> LinearDictionary<K, V>::getKeys() {
    vector<K> key_vector;
    for (int i = 0; i < this->dictionary_vector.size(); i++){
        key_vector.push_back(this->dictionary_vector[i].first);
    }
    return key_vector;
}

template <typename K, typename V>
vector<pair<K, V>> LinearDictionary<K, V>::getItems() {
    vector<pair<K,V>> item_vector;
    for (int i = 0; i < this->dictionary_vector.size(); i++){
        item_vector.push_back(this->dictionary_vector[i]);
    }
    return item_vector;
}
