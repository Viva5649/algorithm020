//
//  LeetCode1.hpp
//  AlgorithmPractice
//
//  Created by viva on 2020/11/25.
//

#ifndef LeetCode1_hpp
#define LeetCode1_hpp

#include "CustomAlgorithm.h"

class LeetCode1 : CustomAlgorithm {
public:
    void Execute() override;
    
private:
    vector<int> TwoSum(vector<int>& nums, int target);
};

#endif /* LeetCode1_hpp */
