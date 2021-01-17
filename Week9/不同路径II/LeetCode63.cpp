//
//  LeetCode63.cpp
//  AlgorithmPractice
//
//  Created by Viva on 2021/1/16.
//

// 题目：不同路径 II

// 思路：动态规划。
// 定义状态 dp[i][j] 表示到从坐标 [0][0] 到坐标 [i][j] 位置的不同路径的数量。
// 若 grid[i][j] == 1，表示有障碍物不可达，dp[i][j] = 0；
// 若 grid[i][j] == 0，表示可达，dp[i][j] = dp[i - 1][j] + dp[i][j - 1]。

#include "LeetCode63.h"

void LeetCode63::Execute() {
    
}

int LeetCode63::UniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    if (obstacleGrid.size() < 1) {
        return 0;
    }
    
    if (obstacleGrid[0].size() < 1) {
        return 0;
    }
    
    if (obstacleGrid[0][0] == 1) {
        return 0;
    }
    
    int pathCount = 0;
    
    int row = (int)obstacleGrid.size();
    int column = (int)obstacleGrid[0].size();
    vector<vector<int>> pathArray(row, vector<int>(column, 0));
    pathArray[0][0] = 1;
    
    // 填充第一行数据
    for (int i = 0; i < column; i++) {
        if (obstacleGrid[0][i] == 1) {
            break;
        } else if (obstacleGrid[0][i] == 0) {
            pathArray[0][i] = 1;
        }
    }
    
    // 填充第一列数据
    for (int i = 0; i < row; i++) {
        if (obstacleGrid[i][0] == 1) {
            break;
        } else if (obstacleGrid[i][0] == 0) {
            pathArray[i][0] = 1;
        }
    }
    
    for (int i = 1; i < row; i++) {
        for (int j = 1; j < column; j++) {
            if (obstacleGrid[i][j] == 1) {
                // 坐标 [i][j] 不可达
                pathArray[i][j] = 0;
            } else if (obstacleGrid[i][j] == 0) {
                // 坐标 [i][j] 可达
                pathArray[i][j] = pathArray[i - 1][j] + pathArray[i][j - 1];
            }
        }
    }
    
    pathCount = pathArray[row - 1][column - 1];
    
    return pathCount;
}
