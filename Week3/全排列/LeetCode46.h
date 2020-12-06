//
//  LeetCode46.hpp
//  AlgorithmPractice
//
//  Created by viva on 2020/12/6.
//

#ifndef LeetCode46_hpp
#define LeetCode46_hpp

#include "CustomAlgorithm.h"

class LeetCode46 : public CustomAlgorithm {
public:
    void Execute() override;
    
private:
    vector<vector<int>> m_resultArray;
    vector<int> m_visitNums;
    
    vector<vector<int>> Permute(vector<int> &nums);
    
    void BackTrace(vector<int> &nums, vector<int> &curResult);
};

#endif /* LeetCode46_hpp */
