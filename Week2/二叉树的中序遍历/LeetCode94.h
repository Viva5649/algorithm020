//
//  LeetCode94.hpp
//  AlgorithmPractice
//
//  Created by viva on 2020/11/25.
//

#ifndef LeetCode94_hpp
#define LeetCode94_hpp

#include "CustomAlgorithm.h"
#include "Tree.h"

class LeetCode94 : CustomAlgorithm {
public:
    void Execute() override;
    
private:
    vector<int> InorderTraversal(BinaryTreeNode  *root);
    
    void RecordInorderValue(BinaryTreeNode *root, vector<int> &valueArray);
};

#endif /* LeetCode94_hpp */
