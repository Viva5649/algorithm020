//
//  LeetCode647.cpp
//  AlgorithmPractice
//
//  Created by viva on 2020/12/27.
//

// 题目：回文子串

// 思路：动态规划。
// 状态定义：dp(i, j) 表示字符串在 [i, j] 区间的子串是否是一个回文串。
// DP 方程：当 s[i] == s[j] 且 (j - i < 2 || dp(i+1, j-1)) 的时候，dp(i, j) = true。
// 当只有 1 个字符时，肯定是一个回文串；
// 当有 2 个字符且字符相等时，肯定是一个回文串；
// 当有 3 个以上字符时，去掉头尾的子串也必定是一个回文串。

#include "LeetCode647.h"

void LeetCode647::Execute() {
    string sampleString = "a";
    int count = CountSubstrings(sampleString);
    
    printf("\n count = %d \n", count);
}

int LeetCode647::CountSubstrings(string s) {
    if (s.length() < 1) {
        return 0;
    }
    
    int count = 0;
    int length = (int)s.length();
    vector<vector<bool>> dp(length, vector<bool>(length, false));
    for (int right = 0; right < length; right++) {
        for (int left = 0; left <= right; left++) {
            if ((s.substr(left, 1) == s.substr(right, 1)) && (right - left < 2 || dp[left+1][right-1])) {
                dp[left][right] = true;
                count++;
            }
        }
    }
    
    return count;
}
