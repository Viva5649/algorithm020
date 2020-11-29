//
//  LeetCode94.cpp
//  AlgorithmPractice
//
//  Created by viva on 2020/11/25.
//

// 题目：二叉树的中序遍历
// 左子树 -> 根 -> 右子树

// 思路1：递归。
// 时间复杂度O(n)
// 空间复杂度O(n)：空间复杂度取决于递归的栈深度，而栈深度在二叉树为一条链的情况下会达到O(n)的级别。

// 思路2：迭代，显式地使用栈。
// 时间复杂度O(n)
// 空间复杂度O(n)

#include "LeetCode94.h"

void LeetCode94::Execute() {
    
}

vector<int> LeetCode94::InorderTraversal(BinaryTreeNode *root) {
    if (root == NULL) {
        return vector<int>();
    }
    
    vector<int> resultArray = {};
    
//    // 思路1
//    RecordInorderValue(root, resultArray);
    
    // 思路2
    stack<BinaryTreeNode *> nodeStack = stack<BinaryTreeNode *>();
    while (root || !nodeStack.empty()) {
        while (root) {
            nodeStack.push(root);
            root = root->left;
        }
        root = nodeStack.top();
        nodeStack.pop();
        resultArray.push_back(root->val);
        root = root->right;
    }
    
    return resultArray;
}

void LeetCode94::RecordInorderValue(BinaryTreeNode *root, vector<int> &valueArray) {
    if (root == NULL) {
        return;
    }
    
    RecordInorderValue(root->left, valueArray);
    valueArray.push_back(root->val);
    RecordInorderValue(root->right, valueArray);
}
