/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <iostream>
#include <string>
#include <vector>

#include "keywordSearcher.h"

using namespace std;

/**
  * Prints the page number and word count for a given word's top 10 occurences. 
  * @param word_data A vector containing all the required 
  *                  page_number, word_count pair.
  * @param word The word that was searched.
*/
void print_word_data(vector<pair<int, int>> word_data, std::string word) {
    if (word_data.size() == 0) {
      cout << "The word " + word + " does not appear in the file." << endl;
    } else {
      cout << "The word " + word + " appears in the file ..." << endl;
      for (int i = 0; i < word_data.size(); i++) {
        cout << "  on page " << word_data[i].first << " (" <<
                                  word_data[i].second << " occurences)" << endl;
      }
    }
}

// Initiation point of the keyword searcher program.
int main(int argc, char** argv) {
  if (argc != 2){
    throw runtime_error("Invalid number of command line arguments!");
  } else {
    KeywordSearcher searcher;
    searcher.loadWords(argv[1]);
    cout << "File loaded successfully!" << endl;
    cout << "" << endl;
    std::string word;
    cout << "Please enter a search word or '!' to quit: ", cin >> word;
    while (word != "!") {
      vector<pair<int, int>> word_data = searcher.search(word);
      print_word_data(word_data, word);
      cout << "" << endl;
      cout << "Please enter a search word or '!' to quit: ", cin >> word;
    }
    cout << "" << endl;
    cout << "Thanks for using me, Goodbye!" << endl;
  }
  return 0;
}
