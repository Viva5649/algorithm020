//
//  LeetCode5.hpp
//  AlgorithmPractice
//
//  Created by Viva on 2021/1/16.
//

#ifndef LeetCode5_hpp
#define LeetCode5_hpp

#include "CustomAlgorithm.h"

class LeetCode5 : public CustomAlgorithm {
public:
    void Execute() override;
    
private:
    string LongestPalindrome(string s);
};

#endif /* LeetCode5_hpp */
