//
//  LeetCode46.cpp
//  AlgorithmPractice
//
//  Created by viva on 2020/12/6.
//

// 题目：全排列
// 给定一个 没有重复 数字的序列，返回其所有可能的全排列。

// 思路：回溯思想。
// 每次取一个数，对于剩下的数，求全排列，递归执行。
// 时间复杂度：O(n!)
// 空间复杂度：O(n)

#include "LeetCode46.h"

void LeetCode46::Execute() {
    vector<int> sampleNumArray = {1, 2, 3};
    vector<vector<int>> resultArray = Permute(sampleNumArray);
    
    for (int i = 0; i < resultArray.size(); i++) {
        vector<int> result = resultArray[i];
        for (int j = 0; j < result.size(); j++) {
            printf("%d", result[j]);
            if (j != result.size() - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
}

vector<vector<int>> LeetCode46::Permute(vector<int> &nums) {
    m_resultArray = {};
    m_visitNums = vector<int>(nums.size(), 0);
    vector<int> curResult = {};
    BackTrace(nums, curResult);
    
    return m_resultArray;
}

void LeetCode46::BackTrace(vector<int> &nums, vector<int> &curResult) {
    if (curResult.size() == nums.size()) {
        m_resultArray.push_back(curResult);
        
        return;
    }
    
    for (int i = 0; i < nums.size(); i++) {
        int curNum = nums[i];
        if (m_visitNums[i] == 1) {
            continue;
        } else {
            m_visitNums[i] = 1;
            curResult.push_back(curNum);
            BackTrace(nums, curResult);
            curResult.pop_back();
            m_visitNums[i] = 0;
        }
    }
}
