//
//  Offer49.cpp
//  AlgorithmPractice
//
//  Created by viva on 2020/11/29.
//

// 题目：丑数
// 我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。
// 1是丑数。
// n不超过1690。

// 思路1：暴力求解，依次判断该数是否为丑数（LeetCode上运行会超时）。

// 思路2：类似动态规划，一个丑数等于（另一个丑数 * 2或3或5）;
// 下一个丑数等于（（当前丑数集合中的丑数 * 2或3或5的结果）中最小的一个）。

#include "Offer49.h"

void Offer49::Execute() {
    int n = 10;
    int uglyNumber = GetUglyNumber(n);
    
    printf("\n %dth uglyNumber = %d \n", n, uglyNumber);
}

int Offer49::GetUglyNumber(int n) {
    if (n <= 0) {
        return 0;
    }
    
//    // 思路1
//    int number = 1;
//    unsigned int count = 0;
//    while (1) {
//        if (JudgeUglyNumber(number)) {
//            count++;
//        }
//
//        if (count == n) {
//            break;
//        }
//
//        number++;
//    }
//
//    return number;
    
    // 思路2
    int t2 = 0;
    int t3 = 0;
    int t5 = 0;
    vector<int> numArray(n);
    numArray[0] = 1;
    for (int i = 1; i < n; i++) {
        numArray[i] = min(numArray[t2]*2, min(numArray[t3]*3, numArray[t5]*5));
        if (numArray[i] == numArray[t2]*2) {
            t2++;
        }
        if (numArray[i] == numArray[t3]*3) {
            t3++;
        }
        if (numArray[i] == numArray[t5]*5) {
            t5++;
        }
    }
    
    return numArray[n-1];
}

bool Offer49::JudgeUglyNumber(int number) {
    if (number > 0 && number <= 6) {
        return true;
    } else if (number <= 0) {
        return false;
    }
    
    while (number % 3 == 0) {
        number /= 3;
    }
    while (number % 5 == 0) {
        number /= 5;
    }
    while (number % 2 == 0) {
        number /= 2;
    }

    return (number == 1);
}
