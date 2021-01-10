//
//  LRUCacheSolution.cpp
//  AlgorithmPractice
//
//  Created by viva on 2020/10/31.
//

// LeetCode #146 LRU缓存机制
// 1、获取数据 get(key)：
// (1) 若关键字key存在于缓存中，则获取关键字的值（总是正数），并将对应节点移至链表头部。
// (2) 若关键字key不存在，则返回-1。
// 2、写入数据 put(key, value)：
// (1) 如果关键字已经存在，则变更其数据值，并将对应节点移至链表头部。
// (2) 如果关键字不存在，则插入该组「关键字/值」。
// 3、当缓存容量达到上限时，在写入新数据之前删除最久未使用的数据值（删除链表尾部节点），从而为新的数据值留出空间。

// 思路：使用双向链表实现，最新的一直插在头部，链表满时删除尾部节点。
// 查找、插入和删除的时间复杂度为O(n)。
// 优化点1：使用dummyHead和dummyTail来简化链表的插入和删除操作。
// 优化点2：使用map来缓存节点key对应的值，可以将查找、插入和删除的时间复杂度优化为O(1)。

#include "LRUCacheSolution.h"

#pragma mark - LRUCache

LRUCache::LRUCache(int capacity) {
    m_nMaxCapacity = capacity;
    m_nCurrentCapacity = 0;
    m_pDummyHead = new DLinkListNode(0, 0, NULL, NULL);
    m_pDummyTail = new DLinkListNode(0, 0, NULL, NULL);
    m_pDummyHead->next = m_pDummyTail;
    m_pDummyTail->prev = m_pDummyHead;
    m_nodeMap = unordered_map<int, DLinkListNode *>();
}

LRUCache::~LRUCache() {
    while (m_pDummyHead->next && m_pDummyHead->next != m_pDummyTail) {
        DLinkListNode *node = m_pDummyHead->next;
        RemoveNode(node);
        delete node;
        node = NULL;
    }
    
    delete m_pDummyHead;
    m_pDummyHead = NULL;
    delete m_pDummyTail;
    m_pDummyTail = NULL;
    
    m_nodeMap.clear();
}

int LRUCache::get(int key) {
    DLinkListNode *node = FindNode(key);
    if (node) {
        // 将节点移动至头部
        RemoveNode(node);
        AddNodeToHead(node);
        
        return node->value;
    } else {
        return -1;
    }
}

void LRUCache::put(int key, int value) {
    DLinkListNode *node = FindNode(key);
    if (node) {
        // 有重复key，将重复节点移动至头部
        RemoveNode(node);
        AddNodeToHead(node);
        // 更新节点的值
        node->value = value;
    } else {
        DLinkListNode *newNode = new DLinkListNode(key, value);
        m_nodeMap[key] = newNode;
        
        if (m_nCurrentCapacity < m_nMaxCapacity) {
            // 无重复key，且链表未满，将新节点插入头部
            AddNodeToHead(newNode);
            
            m_nCurrentCapacity++;
        } else {
            // 无重复key，且链表已满，则先移除链表尾部节点，再讲新节点插入头部
            DLinkListNode *tailNode = m_pDummyTail->prev;
            RemoveNode(tailNode);
            m_nodeMap.erase(tailNode->key);
            delete tailNode;
            tailNode = NULL;
            
            AddNodeToHead(newNode);
        }
    }
}

DLinkListNode* LRUCache::FindNode(int key) {
    unordered_map<int, DLinkListNode*>::iterator it = m_nodeMap.find(key);
    if (it != m_nodeMap.end()) {
        return it->second;
    } else {
        return NULL;
    }
}

void LRUCache::RemoveNode(DLinkListNode *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

void LRUCache::AddNodeToHead(DLinkListNode *node) {
    node->prev = m_pDummyHead;
    node->next = m_pDummyHead->next;
    m_pDummyHead->next->prev = node;
    m_pDummyHead->next = node;
}

#pragma mark - LRUCacheSolution

void LRUCacheSolution::Execute() {
    LRUCache *cache = new LRUCache(2);
    
    cache->put(1, 1);
    int value1 = cache->get(1);
    printf("\n value1 = %d \n", value1);
    
    cache->put(2, 2);
    int value2 = cache->get(2);
    printf("\n value2 = %d \n", value2);
    
    value1 = cache->get(1);
    printf("\n value1 = %d \n", value1);
    
    cache->put(3, 3);
    int value3 = cache->get(3);
    printf("\n value3 = %d \n", value3);
    
    value2 = cache->get(2);
    printf("\n value2 = %d \n", value2);
    
    cache->put(4, 4);
    int value4 = cache->get(4);
    printf("\n value4 = %d \n", value4);
    
    value1 = cache->get(1);
    printf("\n value1 = %d \n", value1);
    
    value3 = cache->get(3);
    printf("\n value3 = %d \n", value3);
    
    value4 = cache->get(4);
    printf("\n value4 = %d \n", value4);
    
    delete cache;
}
