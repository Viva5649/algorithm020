//
//  LeetCode33.hpp
//  AlgorithmPractice
//
//  Created by viva on 2020/12/13.
//

#ifndef LeetCode33_hpp
#define LeetCode33_hpp

#include "CustomAlgorithm.h"

class LeetCode33 : public CustomAlgorithm {
public:
    void Execute() override;
    
private:
    int Search(vector<int>& nums, int target);
};

#endif /* LeetCode33_hpp */
