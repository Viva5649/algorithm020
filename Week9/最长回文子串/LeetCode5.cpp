//
//  LeetCode5.cpp
//  AlgorithmPractice
//
//  Created by Viva on 2021/1/16.
//

// 题目：最长回文子串

// 思路：动态规划。
// 定义状态 dp[i][j] 表示 string.substr(i, j) 是否为一个回文串。
// 若 子串长度 (j - i + 1) > 2，dp[i][j] = (dp[i + 1][j - 1]) && (string[i] == string[j])；
// 若 子串长度为 2，是否回文取决于 string[i] 和 string[j] 是否相同，dp[i][j] = (string[i] == string[j])；
// 若 子串长度为 1，单个字符必定回文，dp[i][j] = true。

#include "LeetCode5.h"

void LeetCode5::Execute() {
    string sampleString = "babadab";
    string result = LongestPalindrome(sampleString);
    
    printf("\n result = %s \n", result.c_str());
}

string LeetCode5::LongestPalindrome(string s) {
    int length = (int)s.length();
    vector<vector<bool>> dp(length, vector<bool>(length, false));
    string result;
    
    int maxLength = 1;
    int beginIndex = 0;
    
    // i 从后往前进行遍历，因为需要从后面短字符串的结果推导前面长字符串的结果，i 的区间是慢慢往后缩进的
    // j 从前往后进行遍历，j 的区间是慢慢往前缩进的
    for (int i = length - 1; i >= 0; i--) {
        for (int j = i; j < length; j++) {
            if (i == j) {
                dp[i][j] = true;
            } else if (j - i == 1) {
                dp[i][j] = (s[i] == s[j]);
            } else {
                dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
            }
            
            if (dp[i][j] && (j - i + 1) > maxLength) {
                beginIndex = i;
                maxLength = j - i + 1;
            }
        }
    }
    
    result = s.substr(beginIndex, maxLength);
    
    return result;
}
