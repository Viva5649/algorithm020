//
//  LeetCode42.hpp
//  AlgorithmPractice
//
//  Created by viva on 2020/11/22.
//

#ifndef LeetCode42_hpp
#define LeetCode42_hpp

#include "CustomAlgorithm.h"

class LeetCode42 : public CustomAlgorithm {
public:
    void Execute() override;
    
private:
    int Trap(vector<int> &heightArray);
};

#endif /* LeetCode42_hpp */
