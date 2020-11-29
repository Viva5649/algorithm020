//
//  LeetCode144.cpp
//  AlgorithmPractice
//
//  Created by viva on 2020/11/25.
//

// 题目：二叉树的前序遍历
// 根 -> 左子树 -> 右子树

// 思路1：递归。
// 时间复杂度O(n)
// 空间复杂度O(n)：空间复杂度取决于递归的栈深度，而栈深度在二叉树为一条链的情况下会达到O(n)的级别。

// 思路2：迭代，显式地使用栈。
// 时间复杂度O(n)
// 空间复杂度O(n)

#include "LeetCode144.h"

void LeetCode144::Execute() {
    
}

vector<int> LeetCode144::PreorderTraversal(BinaryTreeNode *root) {
    if (root == NULL) {
        return vector<int>();
    }
    
    vector<int> resultArray = {};
    
//    // 思路1
//    RecordPreorderValue(root, resultArray);
    
    // 思路2
    stack<BinaryTreeNode *> nodeStack = stack<BinaryTreeNode *>();
    while (root || !nodeStack.empty()) {
        while (root) {
            resultArray.push_back(root->val);
            nodeStack.push(root);
            root = root->left;
        }
        root = nodeStack.top();
        nodeStack.pop();
        root = root->right;
    }
    
    return resultArray;
}

void LeetCode144::RecordPreorderValue(BinaryTreeNode *root, vector<int> &valueArray) {
    if (root == NULL) {
        return;
    }
    
    valueArray.push_back(root->val);
    RecordPreorderValue(root->left, valueArray);
    RecordPreorderValue(root->right, valueArray);
}
