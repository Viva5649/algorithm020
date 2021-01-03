//
//  LeetCode212.cpp
//  AlgorithmPractice
//
//  Created by Viva on 2021/1/2.
//

// 题目：单词搜索 II

// 思路1：遍历 words 里的单词，去 board 中寻找。

// 思路2：根据 words 构建 trie；
// 遍历二维矩阵 board，以其中每一个字符作为起点，做深度优先搜索。

#include "LeetCode212.h"

TrieNode::TrieNode() {
    m_isEnd = false;
    for (int i = 0; i < 26; i++) {
        m_children[i] = NULL;
    }
}

TrieNode::~TrieNode() {
    for (int i = 0; i < 26; i++) {
        if (m_children[i] != NULL) {
            delete m_children[i];
            
            m_children[i] = NULL;
        }
    }
}

void TrieNode::insert(string word) {
    TrieNode *currentNode = this;
    for (char c : word) {
        if (currentNode->m_children[c - 'a'] == NULL) {
            currentNode->m_children[c - 'a'] = new TrieNode();
        }
        currentNode = currentNode->m_children[c - 'a'];
    }
    currentNode->m_isEnd = true;
}

bool TrieNode::search(string word) {
    TrieNode *currentNode = this;
    for (char c : word) {
        currentNode = currentNode->m_children[c - 'a'];
        if (currentNode == NULL) {
            return false;
        }
    }
    
    return currentNode->m_isEnd;
}

bool TrieNode::startsWith(string prefix) {
    TrieNode *currentNode = this;
    for (char c : prefix) {
        currentNode = currentNode->m_children[c - 'a'];
        if (currentNode == NULL) {
            return false;
        }
    }
    
    return true;
}

void LeetCode212::Execute() {
    vector<vector<char>> board = {{'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};
//    vector<string> words = {"oath", "pea", "eat", "rain"};
    vector<string> words = {"oath", "pea", "eat", "rain", "oathi", "oathk", "oathf"};
    vector<string> result = FindWords(board, words);
    
    printf("\n");
    for (string word : result) {
        printf("%s\n", word.c_str());
    }
    printf("\n");
}

vector<string> LeetCode212::FindWords(vector<vector<char>> &board, vector<string> &words) {
    vector<string> result = {};
    
    // 构建 trie
    TrieNode *rootNode = new TrieNode();
    for (string word : words) {
        rootNode->insert(word);
    }
    
    // DFS
    int row = (int)board.size();
    int column = (int)board[0].size();
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            string curStr = "";
            DFS(board, result, rootNode, curStr, i, j);
        }
    }
    
    delete rootNode;
    
    return result;
}

void LeetCode212::DFS(vector<vector<char> > &board, vector<string> &result, TrieNode *root, string curStr, int i, int j) {
    char c = board[i][j];
    
    if (c == '.') {
        return;
    }
    
    curStr += c;
    
    // 先进行重复判断，否则会超过时间限制
    if (find(result.begin(), result.end(), curStr) != result.end()) {
        return;
    }
    
    if (!root->startsWith(curStr)) {
        return;
    }
    
    if (root->search(curStr)) {
        result.push_back(curStr);
    }
    
    board[i][j] = '.';
    
    if (i > 0) {
        DFS(board, result, root, curStr, i - 1, j);
    }
    
    if (j > 0) {
        DFS(board, result, root, curStr, i, j - 1);
    }
    
    if ((i + 1) < board.size()) {
        DFS(board, result, root, curStr, i + 1, j);
    }
    
    if ((j + 1) < board[0].size()) {
        DFS(board, result, root, curStr, i, j + 1);
    }
    
    board[i][j] = c;
}
