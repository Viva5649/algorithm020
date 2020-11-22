//
//  LeetCode283.cpp
//  AlgorithmPractice
//
//  Created by viva on 2020/11/21.
//

// 题目：移动零
// 给定一个数组nums，所有0移动到数组的末尾，同时保持非零元素的相对顺序。

// 思路：双指针，一个记录0的index，另一个记录下一个非0元素的index。

#include "LeetCode283.h"

void LeetCode283::Execute() {
//    vector<int> sampleArray = {0, 1, 0, 3, 12};
    vector<int> sampleArray = {1, 2, 3, 0, 5, 0, 6, 8, 9, 0};
    MoveZeros(sampleArray);
    
    printf("\n");
    for (int i = 0; i < sampleArray.size(); i++) {
        printf("%d", sampleArray[i]);
        if (i != sampleArray.size()-1) {
            printf(", ");
        }
    }
    printf("\n");
}

void LeetCode283::MoveZeros(vector<int> &nums) {
    int zeroIndex = 0;
    
    for (int i = 0; i < nums.size(); i++) {
        if ((nums[i] != 0) && (zeroIndex >= 0)) {
            if (i != zeroIndex) {
                swap(nums[i], nums[zeroIndex]);
            }
            zeroIndex++;
        }
    }
}
