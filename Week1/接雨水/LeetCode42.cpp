//
//  LeetCode42.cpp
//  AlgorithmPractice
//
//  Created by viva on 2020/11/22.
//

// 题目：接雨水
// 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

// 思路：使用栈，遇到比当前栈顶元素大的元素时，可以计算雨水量。

#include "LeetCode42.h"

void LeetCode42::Execute() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
//    vector<int> height = {4, 3, 2, 1, 2, 1, 3};
    int maxArea = Trap(height);
    
    printf("\n maxArea = %d \n", maxArea);
}

int LeetCode42::Trap(vector<int> &height) {
    if (height.size() < 3) {
        return 0;
    }
    
    // 排除第一个非零数前为0的所有元素
    int leftNum = -1;
    int leftIndex = -1;
    for (int i = 0; i < height.size(); i++) {
        if (height[i] != 0) {
            leftNum = height[i];
            leftIndex = i;
            
            break;
        }
    }
    
    if (leftNum == -1) {
        return 0;
    }
    
    int totalArea = 0;
    
    stack<int> indexStack = stack<int>();
    indexStack.push(leftIndex);
    for (int i = leftIndex + 1; i < height.size(); i++) {
        while ((!indexStack.empty()) && (height[indexStack.top()] < height[i])) {
            int currentIndex = indexStack.top();
            indexStack.pop();
            
            if (!indexStack.empty()) {
                int leftIndex = indexStack.top();
                int h = min(height[leftIndex], height[i]) - height[currentIndex];
                int w = i - leftIndex - 1;
                totalArea += w * h;
            }
        }
        indexStack.push(i);
    }
    
    return totalArea;
}
