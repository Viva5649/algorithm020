//
//  LeetCode208.cpp
//  AlgorithmPractice
//
//  Created by Viva on 2021/1/2.
//

// 题目：实现 Trie (前缀树)

// 思路1：使用 map 实现动态插入。

// 思路2：使用容量为26的静态数组（用于存储26个小写字母）。

#include "LeetCode208.h"

Trie::Trie() {
    m_isEnd = false;
    m_children = map<char, Trie *>();
    m_children.clear();
}

Trie::~Trie() {
    auto iter = m_children.begin();
    while (iter != m_children.end()) {
        Trie *node = iter->second;
        if (node != NULL) {
            delete node;
        }
        iter++;
    }
    m_children.clear();
}

void Trie::insert(string word) {
    Trie *currentNode = this;
    for (char c : word) {
        if (currentNode->m_children.count(c) == 0) {
            currentNode->m_children[c] = new Trie();
        }
        currentNode = currentNode->m_children[c];
    }
    currentNode->m_isEnd = true;
}

bool Trie::search(string word) {
    Trie *currentNode = this;
    for (char c : word) {
        auto iter = currentNode->m_children.find(c);
        if (iter == currentNode->m_children.end()) {
            return false;
        }
        currentNode = currentNode->m_children[c];
    }
    
    return currentNode->m_isEnd;
}

bool Trie::startsWith(string prefix) {
    Trie *currentNode = this;
    for (char c : prefix) {
        auto iter = currentNode->m_children.find(c);
        if (iter == currentNode->m_children.end()) {
            return false;
        }
        currentNode = currentNode->m_children[c];
    }
    
    return true;
}

void LeetCode208::Execute() {
    string sampleWord = "VivaLaVida";
    string testWord = "Viva";
    Trie* rootNode = new Trie();
    rootNode->insert(sampleWord);
    bool exist = rootNode->search(sampleWord);
    bool startsWith = rootNode->startsWith(testWord);
    
    printf("\n sampleWord = %s, testWord = %s, exist = %d, startsWith = %d \n", sampleWord.c_str(), testWord.c_str(), exist, startsWith);
}
