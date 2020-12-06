//
//  LeetCode105.cpp
//  AlgorithmPractice
//
//  Created by viva on 2020/12/6.
//

// 题目：从前序与中序遍历序列构造二叉树
// 树中没有重复的元素。

// 思路1：分治思想。
// 根据前序序列，在中序序列中找到根节点，根节点左右的数据就是其左右子树的序列。
// 递归构造子树，使用左右闭区间。
// 优化点1：分治时数组不进行拷贝，直接用下标进行分割。
// 优化点2：使用map对于中序序列建立索引。
// 时间复杂度：O(n)
// 空间复杂度：O(n)

// 思路2：使用栈进行迭代。

#include "LeetCode105.h"

void LeetCode105::Execute() {
    
}

BinaryTreeNode* LeetCode105::BuildTree(vector<int> &preorder, vector<int> &inorder) {
    if ((preorder.size() == 0) || (inorder.size() == 0)) {
        return NULL;
    }
    
    m_inorderMap = unordered_map<int, int>();
    for (int i = 0; i < inorder.size(); i++) {
        m_inorderMap[inorder[i]] = i;
    }
    
    return BuildSubTree(preorder, 0, (int)(preorder.size()-1), inorder, 0, (int)(inorder.size()-1));
}

BinaryTreeNode* LeetCode105::BuildSubTree(vector<int> &preorder, int pBegin, int pEnd, vector<int> &inorder, int iBegin, int iEnd) {
    if ((pBegin > pEnd) || (iBegin > iEnd)) {
        return NULL;
    }
    
    // 前序序列的第一个节点为根节点
    // rootIndex保存根节点在中序序列中的index
    int rootVal = preorder[pBegin];
    int rootIndex = m_inorderMap.find(rootVal)->second;
    // leftNum保存根节点的左子树节点的个数
    int leftNum = rootIndex - iBegin;
    
    BinaryTreeNode *root = new BinaryTreeNode(rootVal);
    
    int leftPreStart = pBegin + 1;// 从根节点后面一个开始
    int leftPreEnd = pBegin + leftNum;
    int leftInStart = iBegin;
    int leftInEnd = rootIndex - 1;
    
    int rightPreStart = pBegin + leftNum + 1;
    int rightPreEnd = pEnd;
    int rightInStart = rootIndex + 1;
    int rightInEnd = iEnd;
    
    // 构造左子树
    root->left = BuildSubTree(preorder, leftPreStart, leftPreEnd, inorder, leftInStart, leftInEnd);
    // 构造右子树
    root->right = BuildSubTree(preorder, rightPreStart, rightPreEnd, inorder, rightInStart, rightInEnd);
    
    return root;
}
