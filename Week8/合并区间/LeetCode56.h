//
//  LeetCode56.hpp
//  AlgorithmPractice
//
//  Created by viva on 2021/1/10.
//

#ifndef LeetCode56_hpp
#define LeetCode56_hpp

#include "CustomAlgorithm.h"

class LeetCode56 : public CustomAlgorithm {
public:
    void Execute() override;
    
private:
    vector<vector<int>> Merge(vector<vector<int>> &intervals);
};

#endif /* LeetCode56_hpp */
