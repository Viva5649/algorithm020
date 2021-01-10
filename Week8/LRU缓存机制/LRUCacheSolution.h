//
//  LRUCacheSolution.hpp
//  AlgorithmPractice
//
//  Created by viva on 2020/10/31.
//

#ifndef LRUCacheSolution_hpp
#define LRUCacheSolution_hpp

#include "CustomAlgorithm.h"

struct DLinkListNode {
    int key;
    unsigned int value;
    DLinkListNode *prev;
    DLinkListNode *next;
    
    DLinkListNode(int key, unsigned int value) : key(key), value(value), prev(nullptr), next(nullptr) {};
    DLinkListNode(int key, unsigned int value, DLinkListNode *prev, DLinkListNode *next) : key(key), value(value), prev(prev), next(next) {};
};

class LRUCache {
public:
    LRUCache(int capacity);
    
    ~LRUCache();
    
    int get(int key);
    
    void put(int key, int value);
    
private:
    int m_nMaxCapacity;
    int m_nCurrentCapacity;
    DLinkListNode *m_pDummyHead;
    DLinkListNode *m_pDummyTail;
    unordered_map<int, DLinkListNode *> m_nodeMap;
    
    DLinkListNode* FindNode(int key);
    void RemoveNode(DLinkListNode *node);
    void AddNodeToHead(DLinkListNode *node);
};

class LRUCacheSolution : public CustomAlgorithm {
public:
    void Execute() override;
};

#endif /* LRUCacheSolution_hpp */
