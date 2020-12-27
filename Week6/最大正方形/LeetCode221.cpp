//
//  LeetCode221.cpp
//  AlgorithmPractice
//
//  Created by viva on 2020/12/27.
//

// 题目：最大正方形

// 思路：动态规划。
// 定义状态：dp(i, j) 表示以 (i, j) 为右下角，且只包含 1 的正方形的边长最大值。
// 若 matrix[i][j] 的值为 0，则该点不可能在正方形中。
// 若 matrix[i][j] 的值为 1，则 dp(i, j) 的值由其上方、左方和左上方的三个相邻位置的 dp 值决定。
// DP 方程：dp(i, j) = min(dp(i-1, j), dp(i-1, j-1), dp(i, j-1) + 1。

#include "LeetCode221.h"

void LeetCode221::Execute() {
    
}

int LeetCode221::MaximalSquare(vector<vector<char> > &matrix) {
    if (matrix.size() < 1) {
        return 0;
    }
    
    if (matrix[0].size() < 1) {
        return 0;
    }
    
    int row = (int)matrix.size();
    int column = (int)matrix[0].size();
    
    // 不额外处理第一行和第一列，不然代码会写的比较累赘
    vector<vector<int>> dp(row, vector<int>(column, 0));
    int lengthOfSide = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (matrix[i][j] == '1') {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = min(min(dp[i-1][j], dp[i-1][j-1]), dp[i][j-1]) + 1;
                }
                lengthOfSide = max(lengthOfSide, dp[i][j]);
            }
        }
    }
    
    return lengthOfSide * lengthOfSide;
}
