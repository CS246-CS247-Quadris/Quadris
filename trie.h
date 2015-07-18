// Assignment 3, Question 3
// Samir Musali[20491904]

#ifndef __TRIE_H__
#define __TRIE_H__
#define NumChars 26
#include <string>

struct TrieNode {
    bool isWord;
    TrieNode *letters[NumChars];
    TrieNode();
    ~TrieNode();

    void insert(const std::string &word);
    void remove(const std::string &word);
    std::string find(const std::string &word);
    int size();
}; // TrieNode

#endif

// Done!
