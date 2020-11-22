//
//  LeetCode26.hpp
//  AlgorithmPractice
//
//  Created by viva on 2020/10/26.
//

#ifndef LeetCode_26_hpp
#define LeetCode_26_hpp

#include "CustomAlgorithm.h"

class LeetCode26 : CustomAlgorithm {
public:
    void Execute() override;
    
private:
    int RemoveDuplicates(vector<int> &nums);
};

#endif /* LeetCode_26_hpp */
