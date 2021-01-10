//
//  LeetCode56.cpp
//  AlgorithmPractice
//
//  Created by viva on 2021/1/10.
//

// 题目：合并区间

// 思路1：暴力求解，遍历每一个区间。

// 思路2：将所有区间的“左端点”进行排序，之后扫描一遍，获得合并后的区间。
// 排序完成后，能够合并成大区间的区间，一定是连续的。

#include "LeetCode56.h"

void LeetCode56::Execute() {
    
}

vector<vector<int>> LeetCode56::Merge(vector<vector<int>> &intervals) {
    if (intervals.size() == 0) {
        return {};
    }
    
    if (intervals.size() == 1) {
        return intervals;
    }
    
    vector<vector<int>> result = {};
    
    // 思路2
    sort(intervals.begin(), intervals.end());
    for (int i = 0; i < intervals.size(); i++) {
        int left = intervals[i][0];
        int right = intervals[i][1];
        if (result.size() == 0 || result.back()[1] < left) {
            result.push_back({left, right});
        } else {
            result.back()[1] = max(result.back()[1], right);
        }
    }
    
    return result;
}
