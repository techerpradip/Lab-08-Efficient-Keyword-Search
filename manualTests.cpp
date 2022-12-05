/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <string>
#include"linearDictionary.h"
#include"hashTable.h"
#include<iostream>
using namespace std;

int main(int argc, char** argv) {
  
  Dictionary<int, string>* dictionary = new HashTable<int, string>();

  for (int i = 0; i < 6; i++) {
    dictionary->insert(i, to_string(i));
    std::cout << dictionary->getSize() << std::endl;
  }

  vector<int> keys_vector = dictionary->getKeys();
  std::cout << keys_vector.size() << std::endl;
  for (int i=0; i < keys_vector.size(); i++) {
    std::cout << keys_vector[i] << std::endl;
  }

  for (int i = 0; i < 6; i++) {
    std::cout << dictionary->get(i) << std::endl;
  }

  delete dictionary;

  return 0;
}
