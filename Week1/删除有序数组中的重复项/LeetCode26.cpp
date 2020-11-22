//
//  LeetCode26.cpp
//  AlgorithmPractice
//
//  Created by viva on 2020/11/21.
//

// 题目：删除排序数组中的重复项
// 数组是有序的，原地删除数组中重复出现的元素，返回移除后数组的新长度。
// 只需要保证不重复的元素存储在数组前部即可，不需要考虑数组中超出新长度后面的元素。

// 思路：使用双指针，分别保存当前遍历到的数字和上一个不重复的数字

#include "LeetCode26.h"

void LeetCode26::Execute() {
    vector<int> numArray = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int size = RemoveDuplicates(numArray);
    
    printf("\n result = %d \n", size);
}

int LeetCode26::RemoveDuplicates(vector<int> &nums) {
    if (nums.size() == 0) {
        return 0;
    }
    
    int j = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[j]) {
            j++;
            nums[j] = nums[i];
        }
    }
    
    return j+1;
}
