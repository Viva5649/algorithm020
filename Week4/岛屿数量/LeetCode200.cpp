//
//  LeetCode200.cpp
//  AlgorithmPractice
//
//  Created by viva on 2020/12/10.
//

// 题目：岛屿数量
// 给钉一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算网格中岛屿的数量。
// 岛屿总是被水包围，并且每座岛屿只能由水平方向和竖直方向上相邻的陆地连接形成。
// 假设该网格的四条边均被水包围。

// 思路1：深度优先搜索。
// 扫描二维数组，每次找到一个陆地后，进行计数，
// 同时将该陆地四周水平和垂直方向的陆地都标记为0。

#include "LeetCode200.h"

void LeetCode200::Execute() {
    vector<char> row1 = {'1', '1', '0', '0', '0'};
    vector<char> row2 = {'1', '1', '0', '0', '0'};
    vector<char> row3 = {'0', '0', '1', '0', '0'};
    vector<char> row4 = {'0', '0', '0', '1', '1'};
    vector<vector<char>> sampleGrid = {row1, row2, row3, row4};
    int num = GetNumOfIslands(sampleGrid);
    
    printf("\n numberOfIslands = %d \n", num);
}

int LeetCode200::GetNumOfIslands(vector<vector<char>> &grid) {
    if (grid.size() < 1) {
        return 0;
    }
    
    int num = 0;
    
    // 思路1
    m_matrixHeight = (int)grid.size();
    m_matrixWidth = (int)grid[0].size();
    for (int i = 0; i < m_matrixHeight; i++) {
        for (int j = 0; j < m_matrixWidth; j++) {
            if (grid[i][j] == '1') {
                num++;
                DFS(grid, i, j);
            }
        }
    }
    
    return num;
}

void LeetCode200::DFS(vector<vector<char>> &grid, int i, int j) {
    grid[i][j] = '0';
    
    if ((i - 1) >= 0) {
        if (grid[i - 1][j] == '1') {
            DFS(grid, i - 1, j);
        }
    }
    
    if ((i + 1) < m_matrixHeight) {
        if (grid[i + 1][j] == '1') {
            DFS(grid, i + 1, j);
        }
    }
    
    if ((j - 1) >= 0) {
        if (grid[i][j - 1] == '1') {
            DFS(grid, i, j - 1);
        }
    }
    
    if ((j + 1) < m_matrixWidth) {
        if (grid[i][j + 1] == '1') {
            DFS(grid, i, j + 1);
        }
    }
}
