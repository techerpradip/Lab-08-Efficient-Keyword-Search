#pragma once

/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <string>
#include <vector>
#include "hashTable.h"

/**s
 * This class represents a tool which can be used to perform a keyword search on
 * a document.  The user of this class instantiates it, updates it with words
 * from a document, and can then use it to identify the pages on which specific
 * words appear most frequently.
 */
class KeywordSearcher {
  public:
    /**
     * Creates a new keyword searcher with no data.
     */
    KeywordSearcher();

    /**
     * Destructs a KeywordSearcher and releases the memory it is using.
     */
    ~KeywordSearcher();

    /**
     * Loads the words from a given file into this searcher.
     * @param filename The name of the text file to use.
     */
    void loadWords(std::string filename);

    /**
     * Searches this object to find the pages on which a particular word most
     * frequently appeared.
     * @param word The word to find.
     * @return A vector of pairs between page numbers and occurrences.  The top
     *         ten pages are returned, ordered from most to least occurrences.
     *         All pairs have a positive (non-zero) number of occurrences; if a
     *         word appears on fewer than ten pages, the returned vector
     *         contains fewer than ten elements.
     */
    std::vector<std::pair<int, int>> search(std::string word);

  private:
    /**
     * implementing keyword_dctionary as a HashTable keyed on the unique words
     * and valued on the pointers to a dynamically allocated HashTable keyed on 
     * page number and valued on word count.
     */
    HashTable<std::string, HashTable<int, int>*> keyword_dictionary;

    /**
     * Updates the word count for a word that already exists 
     * in the keyword dictionary.
     * @param word The word whose word count needs to be updated.
     * @param page_number page number for the word's count to be updated.
     */
    void update_word_count(std::string word, int page_number);

    /**
     * Insert a new word in the keyword dictionary.
     * @param word The word that is to be inserted.
     * @param page_number page number where the word is to be inserted.
     */
    void insert_new_word(std::string word, int page_number);
};
