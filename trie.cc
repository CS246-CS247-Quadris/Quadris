// Assignment 3, Question 3
// Samir Musali[20491904]

#include <iostream>
#include "trie.h"
#include <string>
using namespace std;

// Default Ctor:
TrieNode::TrieNode() {
	for(int i = 0; i < NumChars; i++) this->letters[i] = 0;
	this->isWord = false;
}

// insert member function:
void TrieNode::insert(const std::string &word) {
	int len = word.length();
	char first = word[0];
	int pos = first - 'a';
	if (!this->letters[pos]) this->letters[pos] = new TrieNode;
	if (len == 1) {
		this->letters[pos]->isWord = true;
	}
	else {
		string sub = word.substr(1,len - 1);
		this->letters[pos]->insert(sub);
	}
}

// remove member function:
void TrieNode::remove(const std::string &word) {
	int len = word.length();
	char first = word[0];
	int pos = first - 'a';
	if (this->letters[pos]) {
		if (len == 1) {
			this->letters[pos]->isWord = false;
		}
		else {
			string sub = word.substr(1,len - 1);
			this->letters[pos]->remove(sub);
		}
	}
}
// NOTE: Just switching isWord to false in every required node

bool situation(TrieNode *t) {
	bool d = false;
	for (int i = 0; i < NumChars; i++) {
		if (t->letters[i]) {
			d = d or t->letters[i]->isWord;
			d = d or situation(t->letters[i]);
		}
	}
	return d;
}

// find member function
string TrieNode::find(const string &word) {
	TrieNode *cur = this;
	string result;
	for (int i = 0; word[i]; i++) {
		char node = word[i];
		int pos = node - 'a';
		if (!cur->letters[pos]) return "";
		cur = cur->letters[pos];
	}
	if (!cur->isWord) {
		result = "";
		if (situation(cur) == false) {
			delete cur;
			return "";
		}
	}
	else result = word;
	for (int i = 0; i < NumChars; i++) {
		if (cur->letters[i]) {
			char let = 'a' + i;
			string next = word + let;
			string result_next = find(next);
			if (result_next != "") {
				if (result == "") {
					result = result + result_next;
				}
				else {
					result = result + " ";
					result = result + result_next;
				}
			}
		}
	}
	return result;
}

// counting helper function:
int counting(TrieNode *trie) {
	int c = 0;
	for (int i = 0; i < NumChars; i++) {
		if (trie->letters[i]) {
			c += counting(trie->letters[i]);
		}
	}
	return c + 1;
}

// size member function:
int TrieNode::size() {
	return counting(this);
}

// destructor:
TrieNode::~TrieNode() {
	for (int i = 0; i < NumChars; i++) { 
		if (this->letters[i]) {
			delete this->letters[i]; 
		}
	}
}
