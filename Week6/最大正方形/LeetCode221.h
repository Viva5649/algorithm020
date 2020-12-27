//
//  LeetCode221.hpp
//  AlgorithmPractice
//
//  Created by viva on 2020/12/27.
//

#ifndef LeetCode221_hpp
#define LeetCode221_hpp

#include "CustomAlgorithm.h"

class LeetCode221 : public CustomAlgorithm {
public:
    void Execute() override;
    
private:
    int MaximalSquare(vector<vector<char>>& matrix);
};

#endif /* LeetCode221_hpp */
