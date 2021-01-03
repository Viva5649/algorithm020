//
//  LeetCode212.hpp
//  AlgorithmPractice
//
//  Created by Viva on 2021/1/2.
//

#ifndef LeetCode212_hpp
#define LeetCode212_hpp

#include "CustomAlgorithm.h"

class TrieNode {
public:
    /** Initialize your data structure here. */
    TrieNode();
    
    ~TrieNode();
    
    /** Inserts a word into the trie. */
    void insert(string word);
    
    /** Returns if the word is in the trie. */
    bool search(string word);
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix);
    
private:
    bool m_isEnd;
    TrieNode* m_children[26];
};

class LeetCode212 : CustomAlgorithm {
public:
    void Execute() override;
    
private:
    vector<string> FindWords(vector<vector<char>> &board, vector<string> &words);
    
    void DFS(vector<vector<char>> &board, vector<string> &result, TrieNode *root, string curStr, int i, int j);
};

#endif /* LeetCode212_hpp */
