#ifndef DIVIDETWOINTEGERS_H
#define DIVIDETWOINTEGERS_H

#include<iostream>

using namespace std;

#include <stdlib.h>

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==0)
            return INT_MAX;

        long long divd = dividend;
        long long divs = divisor;
        long long result = 0;
        bool bneg = false;
        if(dividend<0) {
            bneg = !bneg;
            divd = - divd;
        }

        if(divisor<0) {
            bneg = !bneg;
            divs = - divs;
        }

        while(divd>=divs){
            long long a = divs;
            for(int i=1; a<=divd; a<<=1,i<<=1){
                divd -= a;
                result += i;
            }

        }

        if(bneg){
            result = -result;
        }

        int ret = 0;
        if(result>INT_MAX){
            ret = INT_MAX;
        }else if(result<INT_MIN){
            ret = INT_MIN;
        }else{
            ret = result;
        }

        return ret;


//        long long a = dividend;
//        long long b = divisor;
//        a = abs(a); b = abs(b);
//        int res = 0;
//        while (a>=b)
//        {
//            long long t = b;
//            for (int i = 1; a >= t; i <<= 1, t <<= 1)
//            {
//                a -= t;
//                res += i;
//            }
//        }
//        return ((dividend<0)^(divisor<0))? -res:res;

    }
};


void test_divide_two_integers(){
    Solution solv;
//    std::cout<<solv.divide(4, 2)<<std::endl;
//    std::cout<<solv.divide(4, 3)<<std::endl;
//    std::cout<<solv.divide(4, -3)<<std::endl;
    std::cout<<solv.divide(-2147483648, -1)<<std::endl;
    std::cout<<solv.divide(-2147483648, 1)<<std::endl;

}

#endif // DIVIDETWOINTEGERS_H
