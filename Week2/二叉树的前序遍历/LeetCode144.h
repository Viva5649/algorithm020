//
//  LeetCode144.hpp
//  AlgorithmPractice
//
//  Created by viva on 2020/11/25.
//

#ifndef LeetCode144_hpp
#define LeetCode144_hpp

#include "CustomAlgorithm.h"
#include "Tree.h"

class LeetCode144 : CustomAlgorithm {
public:
    void Execute() override;
    
private:
    vector<int> PreorderTraversal(BinaryTreeNode *root);
    
    void RecordPreorderValue(BinaryTreeNode *root, vector<int> &valueArray);
};

#endif /* LeetCode144_hpp */
