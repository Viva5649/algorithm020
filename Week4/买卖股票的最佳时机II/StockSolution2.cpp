//
//  StockSolution2.cpp
//  AlgorithmPractice
//
//  Created by zhangchenliang on 2020/11/4.
//

// LeetCode #122 买卖股票的最佳时机II
// 可以多次买卖股票，只能在买入后再卖出股票，并且再次买入前必须先卖掉原先的股票。

// 思路1：贪心思想。
// 遍历一遍价格，保存当前价格值。
// 遇到更高的就卖掉然后更新利润和价格，遇到更低的就保存更低的价格。

// 思路2：动态规划。
// 定义状态 status[i][0] 表示第 i 天交易完成后手里没有股票情况下的最大利润。
// status[i][1] 表示第 i 天交易完成后手里持有一支股票情况下的最大利润。
// 若前一天结束的时候手里持有一支股票，这时要将其卖出，并获得 prices[i] 的收益。
// status[i][0] = max(status[i-1][0], status[i-1][1]+prices[i])
// 若前一天结束时还没有股票，这时要将其买入，并减少 prices[i] 的收益。
// status[i][1] = max(status[i-1][1], status[i-1][0]-prices[i])

#include "StockSolution2.h"

void StockSolution2::Execute() {
    vector<int> priceArray = {7, 1, 5, 3, 6, 4};
//    vector<int> priceArray = {1, 2, 3, 4, 5, 6};
    int maxProfit = CalculateMaxProfit(priceArray);
    
    printf("\n maxProfit = %d \n", maxProfit);
}

int StockSolution2::CalculateMaxProfit(vector<int> prices) {
    if (prices.size() <= 1) {
        return 0;
    }
    
    int maxProfit = 0;
    
    // 思路1
    int currentPrice = prices[0];
    for (int i = 1; i < prices.size(); i++) {
        if (currentPrice < prices[i]) {
            int profit = prices[i] - currentPrice;
            maxProfit += profit;
            currentPrice = prices[i];
        } else if (currentPrice > prices[i]) {
            currentPrice = prices[i];
        }
    }
    
//    //思路2
//    vector<vector<int>> status(prices.size(), vector<int>(2, 0));
//    status[0][0] = 0;
//    status[0][1] = 0 - prices[0];
//    for (int i = 1; i < prices.size(); i++) {
//        status[i][0] = max(status[i-1][0], status[i-1][1]+prices[i]);
//        status[i][1] = max(status[i-1][1], status[i-1][0]-prices[i]);
//    }
//    maxProfit = status[prices.size()-1][0];
    
    return maxProfit;
}
