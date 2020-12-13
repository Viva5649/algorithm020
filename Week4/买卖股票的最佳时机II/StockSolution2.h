//
//  StockSolution2.hpp
//  AlgorithmPractice
//
//  Created by zhangchenliang on 2020/11/4.
//

#ifndef StockSolution2_hpp
#define StockSolution2_hpp

#include "CustomAlgorithm.h"

class StockSolution2 : public CustomAlgorithm {
public:
    void Execute() override;
    
private:
    int CalculateMaxProfit(vector<int> prices);
};

#endif /* StockSolution2_hpp */
