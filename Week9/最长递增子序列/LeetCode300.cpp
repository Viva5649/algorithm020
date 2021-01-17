//
//  LeetCode300.cpp
//  AlgorithmPractice
//
//  Created by Viva on 2021/1/16.
//

// 题目：最长递增子序列

// 思路：动态规划。
// 定义状态 dp[i] 表示到第 i 个字符为止，最长递增子序列的长度。
// 设 j ∈ [0,i)，每轮计算新 dp[i] 时，遍历 [0,i) 列表区间，做以下判断：
// 当 nums[i] > nums[j] 时，nums[i] 可以接在 nums[j] 之后，此情况下最长上升子序列长度为 dp[j] + 1；
// 当 nums[i] <= nums[j] 时，nums[i] 无法接在 nums[j] 之后，此情况上升子序列不成立，跳过。
// 因此每次遍历 j 时，执行 dp[i] = max(dp[i], dp[j] + 1)。

#include "LeetCode300.h"

void LeetCode300::Execute() {
    
}

int LeetCode300::LengthOfLIS(vector<int> &nums) {
    if (nums.size() < 1) {
        return 0;
    }
    
    int length = 1;
    
    vector<int> dp(nums.size(), 1);
    for (int i = 1; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    length = *max_element(dp.begin(), dp.end());
    
    return length;
}
