//
//  LeetCode63.hpp
//  AlgorithmPractice
//
//  Created by Viva on 2021/1/16.
//

#ifndef LeetCode63_hpp
#define LeetCode63_hpp

#include "CustomAlgorithm.h"

class LeetCode63 : public CustomAlgorithm {
public:
    void Execute() override;
    
private:
    int UniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);
};

#endif /* LeetCode63_hpp */
