
 // #include "TrieNode.h"
#include <string>
#include <vector>
class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
	}
};
class Trie {
	TrieNode *root;

	public :
	int count;

	Trie() {
		this->count = 0;
		root = new TrieNode('\0');
	}

	bool insertWord(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
			if (!root->isTerminal) {
				root -> isTerminal = true;
				return true;	
			} else {
				return false;
			}
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			child = new TrieNode(word[0]);
			root -> children[index] = child;
		}

		// Recursive call
		return insertWord(child, word.substr(1));
	}

	// For user
	void insertWord(string word) {
		if (insertWord(root, word)) {
			this->count++;
		}
	}
  bool search(TrieNode* root,string pattern)
  {
    if(pattern.size()==0)
      return true;
    int i=pattern[0]-'a';
    if(root->children[i]!=NULL)
      return search(root->children[i],pattern.substr(1));
    else
      return false;
  }
  bool search(string pattern)
  {
    return search( root,pattern);
  }

	bool patternMatching(vector<string> vect, string pattern) {
	int l=vect.size();
      if(l==0 &&pattern.size()!=0)
        return false;
      if(pattern.size()==0)
        return true;
      int i=0;
      while(i<l)
      {
        string s=vect[i];
       int j=s.length();
        int k=0;
        while(k<j)
          insertWord(s.substr(k++));
        i++;
      }
      return search(pattern);
      

	}
};

