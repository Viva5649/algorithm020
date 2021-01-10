//
//  LeetCode191.cpp
//  AlgorithmPractice
//
//  Created by viva on 2021/1/10.
//

// 题目：位1的个数

// 思路1：循环 32 次，每次判断当前位是否为二进制的 1 。

// 思路2：每次“模2”或者“与1”，目的是看最后一位是否为 1；再整体右移一位，接着继续看最后一位。

// 思路3：使用 X&(X-1) 的操作，可以将 X 中最低位的 1 变成 0，并保持其他位不变。

#include "LeetCode191.h"

void LeetCode191::Execute() {
    
}

int LeetCode191::GetHammingWeight(uint32_t n) {
    int count = 0;
    
    // 思路1
    uint32_t mask = 1;
    for (int i = 0; i < 32; i++) {
        if ((n & mask) != 0) {
            count++;
        }
        
        mask = mask << 1;
    }
    
    // 思路2
    while (n > 0) {
        uint32_t result = n & 1;
        if (result == 1) {
            count++;
        }
        
        n = n >> 1;
    }
    
    // 思路3
    while (n > 0) {
        count++;
        n = n & (n - 1);
    }
    
    return count;
}
