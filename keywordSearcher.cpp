/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include "hashFunctions.h"
#include "keywordSearcher.h"
#include "adts/stlMaxPriorityQueue.h"
#include "hashTable.h"

#include <stdexcept>
#include <fstream>
#include <string>

using namespace std;

KeywordSearcher::KeywordSearcher() {
    return;
}

KeywordSearcher::~KeywordSearcher() {
    vector<pair<std::string, HashTable<int, int>*>> items;
    items = keyword_dictionary.getItems();
    for (int i = 0; i < items.size(); i++) {
        delete items[i].second;
    }
}

void KeywordSearcher::loadWords(string filename) {
    ifstream text_file;
    text_file.open(filename);
    if(!text_file.is_open()) {
        throw runtime_error("file " + filename + " failed to open!");
    }
    std::string current_word;
    int page_number;
    text_file >> current_word;
    while (!text_file.eof()) {
        if (current_word == "$$@@$$PAGE:") {
            text_file >> current_word;
            page_number = stoi(current_word);
        } else {
            if (keyword_dictionary.contains(current_word)) {
                update_word_count(current_word, page_number);
            } else {
                insert_new_word(current_word, page_number);
            }
        }
        text_file >> current_word;
    }

}

vector<pair<int, int>> KeywordSearcher::search(string word) {
    vector<pair<int, int>> results_vector;
    if (keyword_dictionary.contains(word)) {
        vector<pair<int, int>> word_dataVector = 
                                    keyword_dictionary.get(word)->getItems();
        for (int i = 0; i < word_dataVector.size(); i++) {
            pair<int, int> data_pair(word_dataVector[i].second, word_dataVector[i].first);
            results_vector.push_back(data_pair);
        }
        STLMaxPriorityQueue<int, int> priority_items(results_vector);
        results_vector.clear();
        while (priority_items.getSize() != 0 && results_vector.size() < 10) {
            int word_count = priority_items.peekPriority();
            int page_number = priority_items.remove();
            pair<int, int> priority_data_pair(page_number, word_count);
            results_vector.push_back(priority_data_pair);
        }
        return results_vector;
    } else {
        return results_vector;
    }
}

void KeywordSearcher::update_word_count(string word, int page_number) {
    HashTable<int, int>* unique_wordDict = keyword_dictionary.get(word);
    if (unique_wordDict->contains(page_number)) {
        unique_wordDict->update(page_number, unique_wordDict->get(page_number) + 1);
    } else {
        unique_wordDict->insert(page_number, 1);
    }
}

void KeywordSearcher::insert_new_word(string word, int page_number) {
    HashTable<int, int>* unique_wordDict = new HashTable<int, int>();
    unique_wordDict->insert(page_number, 1);
    keyword_dictionary.insert(word, unique_wordDict);
}