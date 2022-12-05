#pragma once

/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <utility> // for the "pair" STL class
#include <vector>
#include "linearDictionary.h"
#include "adts/dictionary.h"

template <typename K, typename V> class HashTable : public Dictionary<K, V> {
  public:
    /**
     * Creates a new HashTable with a maximum load factor of 0.75.
     */
    HashTable();

    /**
     * Creates a new HashTable.
     * @param maxLoadFactor The maximum load factor which will be permitted
     *                      before this hash table changes its capacity.
     */
    HashTable(float maxLoadFactor);
    /**
     * Cleans up this HashTable.
     */
    ~HashTable();

    /* Dictionary ADT Methods.
       You must implement these acording to ADT specification
     */
    int getSize();
    bool isEmpty();
    void insert(K key, V value);
    void update(K key, V value);
    V get(K key);
    bool contains(K key);
    void remove(K key);
    vector<K> getKeys();
    vector<pair<K, V>> getItems();

  private:
    float load_factor; // load factor of the hash table.
    int size;          // size of the hash table.
    int capacity;      // capacity of the hash table.

    /**
     * implementing hash table as a dynamically allocated 
     * array of Linear Dictionary objects.
    */
    LinearDictionary<K, V>* hash_table;

    /**
     * Maintains the hash table (expands) based on its maximum load factor.
     * @param current_load Current load factor of the heap.
     */
    void maintain_hash_load(float current_load);
};

#include "hashTable-inl.h"
