//
//  LeetCode208.hpp
//  AlgorithmPractice
//
//  Created by Viva on 2021/1/2.
//

#ifndef LeetCode208_hpp
#define LeetCode208_hpp

#include "CustomAlgorithm.h"

class Trie {
public:
    /** Initialize your data structure here. */
    Trie();
    
    ~Trie();
    
    /** Inserts a word into the trie. */
    void insert(string word);
    
    /** Returns if the word is in the trie. */
    bool search(string word);
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix);
    
private:
    bool m_isEnd;
    map<char, Trie *> m_children;
};

class LeetCode208 : CustomAlgorithm {
public:
    void Execute() override;
};

#endif /* LeetCode208_hpp */
