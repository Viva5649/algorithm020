//
//  LeetCode283.hpp
//  AlgorithmPractice
//
//  Created by viva on 2020/11/19.
//

#ifndef LeetCode283_hpp
#define LeetCode283_hpp

#include "CustomAlgorithm.h"

class LeetCode283 : CustomAlgorithm {
public:
    void Execute() override;
    
private:
    void MoveZeros(vector<int> &nums);
};

#endif /* LeetCode283_hpp */
