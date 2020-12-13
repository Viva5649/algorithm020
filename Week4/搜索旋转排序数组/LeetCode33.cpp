//
//  LeetCode33.cpp
//  AlgorithmPractice
//
//  Created by viva on 2020/12/13.
//

// 题目：搜索旋转排序数组
// 给定一个整数数组 nums 和一个整数 target。
// 该整数数组原本是按升序排列，但输入时在预先未知的某个点上进行了旋转。
// 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2]。
// 在数组中搜索 target，如果数组中存在这个目标值，则返回它的索引，否则返回 -1。
// 数组中不存在重复的元素，算法时间复杂度必须是 O(logn) 级别。

// 思路1：暴力求解，使用 O(logn) 的时间复杂度还原升序数组。

// 思路2：二分查找。
// 借助数组头部元素来确定 target 和 mid 的位置关系。
// 升序数组如果进行了旋转，后半段的最大值一定小于前半段的最小值。
// 一定要合理处理 mid 和 target 在判断前后段位置时与 first 的等于关系。
// 要判断的内容：
// 1、mid 在前半段还是后半段？
// 2、target 在 mid 的左边还是右边？

#include "LeetCode33.h"

void LeetCode33::Execute() {
//    vector<int> sampleNumArray = {4, 5, 6, 7, 0, 1, 2, 3};
    vector<int> sampleNumArray = {1, 3};
    int target = 3;
    int index = Search(sampleNumArray, target);
    
    printf("\n target = %d, index = %d \n", target, index);
}

int LeetCode33::Search(vector<int> &nums, int target) {
    if (nums.size() < 1) {
        return -1;
    }
    
    int index = -1;
    
    // 思路2
    int left = 0;
    int right = (int)nums.size() - 1;
    int first = nums[0];
    int mid = (left + right) / 2;
    while (left <= right) {
        if (nums[mid] == target) {
            index = mid;
            
            break;
        }
        
        // 先确定 mid 在前半段还是后半段
        if (nums[mid] >= first) {
            // mid 在前半段
            if (nums[mid] > target) {
                // num[mid] 大于 target，需要找到 target 与 mid 的关系
                if (target >= first) {
                    // target 在 mid 左侧
                    right = mid - 1;
                } else {
                    // target 在 mid 右侧
                    left = mid + 1;
                }
            } else {
                // target 一定在 mid 右侧
                left = mid + 1;
            }
        } else {
            // mid 在后半段
            if (nums[mid] > target) {
                // target 一定在 mid 左侧
                right = mid - 1;
            } else {
                // num[mid] 小于 target，需要找到 target 与 mid 的关系
                if (target >= first) {
                    // target 在 mid 左侧
                    right = mid - 1;
                } else {
                    // target 在 mid 右侧
                    left = mid + 1;
                }
            }
        }
        
        mid = (left + right) / 2;
    }
    
    return index;
}
