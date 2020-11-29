//
//  LeetCode1.cpp
//  AlgorithmPractice
//
//  Created by viva on 2020/11/25.
//

// 题目：两数之和

// 思路1：暴力求解，双重循环。
// 时间复杂度O(n^2)
// 空间复杂度O(1)

// 思路2：使用哈希表，对于每个元素a，在数组中寻找（target - a）是否存在。
// 时间复杂度O(n)
// 空间复杂度O(n)

#include "LeetCode1.h"

void LeetCode1::Execute() {
    vector<int> sampleArray = {2, 7, 11, 15};
    int target = 9;
    vector<int> resultArray = TwoSum(sampleArray, target);
    
    for (int i = 0; i < resultArray.size(); i++) {
        printf("\n number = %d \n", resultArray[i]);
    }
}

vector<int> LeetCode1::TwoSum(vector<int>& nums, int target) {
    if (nums.size() < 2) {
        return vector<int>();
    }
    
    vector<int> resultArray = {};
    
//    // 思路1
//    for (int i = 0; i < nums.size() - 1; i++) {
//        for (int j = i + 1; j < nums.size(); j++) {
//            if (nums[i] + nums[j] == target) {
//                resultArray.push_back(i);
//                resultArray.push_back(j);
//
//                break;
//            }
//        }
//    }
    
    // 思路2
    map<int, int> numMap = map<int, int>();
    for (int i = 0; i < nums.size(); i++) {
        int curNum = nums[i];
        map<int, int>::iterator it = numMap.find(target - curNum);;
        if (it != numMap.end()) {
            resultArray.push_back(it->second);
            resultArray.push_back(i);
            
            break;
        } else {
            numMap[curNum] = i;
        }
    }
    
    return resultArray;
}
