//
//  Offer49.hpp
//  AlgorithmPractice
//
//  Created by viva on 2020/11/29.
//

#ifndef Offer49_hpp
#define Offer49_hpp

#include "CustomAlgorithm.h"

class Offer49 : CustomAlgorithm {
public:
    void Execute() override;
    
private:
    int GetUglyNumber(int n);
    
    bool JudgeUglyNumber(int number);
};

#endif /* Offer49_hpp */
