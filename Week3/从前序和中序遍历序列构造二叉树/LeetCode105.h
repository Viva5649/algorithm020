//
//  LeetCode105.hpp
//  AlgorithmPractice
//
//  Created by viva on 2020/12/6.
//

#ifndef LeetCode105_hpp
#define LeetCode105_hpp

#include "CustomAlgorithm.h"
#include "Tree.h"

class LeetCode105 : public CustomAlgorithm {
public:
    void Execute() override;
    
private:
    // 中序序列，key为节点值，value为节点在数组中的索引
    unordered_map<int, int> m_inorderMap;
    
    BinaryTreeNode* BuildTree(vector<int> &preorder, vector<int> &inorder);
    
    
    /// 构建子树
    /// @param preorder 前序序列
    /// @param pBegin 前序序列的左边界
    /// @param pEnd 前序序列的右边界
    /// @param inorder 中序序列
    /// @param iBegin 中序序列的左边界
    /// @param iEnd 中序序列的的右边界
    BinaryTreeNode* BuildSubTree(vector<int> &preorder, int pBegin, int pEnd, vector<int> &inorder, int iBegin, int iEnd);
};

#endif /* LeetCode105_hpp */
