//
//  LeetCode200.hpp
//  AlgorithmPractice
//
//  Created by viva on 2020/12/10.
//

#ifndef LeetCode200_hpp
#define LeetCode200_hpp

#include "CustomAlgorithm.h"

class LeetCode200 : public CustomAlgorithm {
public:
    void Execute() override;
    
private:
    int m_matrixHeight = 0;
    int m_matrixWidth = 0;
    
    int GetNumOfIslands(vector<vector<char>> &grid);
    
    void DFS(vector<vector<char>> &grid, int i, int j);
};

#endif /* LeetCode200_hpp */
