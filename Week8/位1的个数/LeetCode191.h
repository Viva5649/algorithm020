//
//  LeetCode191.hpp
//  AlgorithmPractice
//
//  Created by viva on 2021/1/10.
//

#ifndef LeetCode191_hpp
#define LeetCode191_hpp

#include "CustomAlgorithm.h"

class LeetCode191 : public CustomAlgorithm {
public:
    void Execute() override;
    
private:
    int GetHammingWeight(uint32_t n);
};

#endif /* LeetCode191_hpp */
