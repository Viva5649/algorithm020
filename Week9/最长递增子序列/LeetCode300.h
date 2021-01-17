//
//  LeetCode300.hpp
//  AlgorithmPractice
//
//  Created by Viva on 2021/1/16.
//

#ifndef LeetCode300_hpp
#define LeetCode300_hpp

#include "CustomAlgorithm.h"

class LeetCode300 : public CustomAlgorithm {
public:
    void Execute() override;
    
private:
    int LengthOfLIS(vector<int>& nums);
};

#endif /* LeetCode300_hpp */
