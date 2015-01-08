#ifndef SUM_H
#define SUM_H

/*
 * https://oj.leetcode.com/problems/3sum/
 * 3Sum Total Accepted: 35106 Total Submissions: 210123 My Submissions Question Solution
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
 * Find all unique triplets in the array which gives the sum of zero.
 *
 * Note:
 * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 * The solution set must not contain duplicate triplets.
 *     For example, given array S = {-1 0 1 2 -1 -4},
 *
 *     A solution set is:
 *     (-1, 0, 1)
 *     (-1, -1, 2)
 *
 */

#include <vector>
using std::vector;
#include <algorithm>

class Solution {
public:
    /**
     * @brief threeSum
     * @param num
     * @return
     */
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > data;

        std::sort(num.begin(), num.end()/*, Solution::cmpfunc*/);

        vector<int> array(3);
        int n = num.size();
        for(int ic=2; ic<n; ++ic){
            if(num[ic]<(0/3)){
                continue;
            }
            if(ic<n-1 && num[ic]==num[ic+1]){
                continue;
            }

            // 以下代码时间复杂度为 O(log2(n))
            for(int ia=0; (ia<ic-1) && (num[ia]<=(0-num[ic])/2); ++ia){
                if(ia && num[ia]==num[ia-1]){
                    continue;
                }
                int numb =  0 - num[ia] - num[ic];
                for(int imin=ia+1, imax=ic-1; imin<=imax; ){
                    int ib = (imin + imax)/2;
                    if(num[ib]<numb){
                        imin = ib+1;
                    }else if(num[ib]>numb){
                        imax = ib-1;
                    }else{
                        array[0] = (num[ia]);
                        array[1] = (num[ib]);
                        array[2] = (num[ic]);
                        data.push_back(array);
                        break;
                    }
                }
            }


            // 以下代码时间复杂度为 O(n)
//            for(int ia = 0, ib = ic-1; ia<ib && (num[ia]<=(0-num[ic])/2); ){
//                if(ia && num[ia]==num[ia-1]) {
//                    ++ia;
//                    continue;
//                }
//                if(ib<ic-1 && num[ib]==num[ib+1]) {
//                    --ib;
//                    continue;
//                }
//                int sumabc = num[ia] + num[ib] + num[ic];
//                if(sumabc<0){
//                    ++ia;
//                }else if(sumabc>0){
//                    --ib;
//                }else{
//                    array[0] = (num[ia]);
//                    array[1] = (num[ib]);
//                    array[2] = (num[ic]);
//                    data.push_back(array);
//                    ++ia;
//                    --ib;
//                }
//            }
        }

        return data;
    }
private:
    static bool cmpfunc(const int& i, const int& j){
        return i<j;
    }
};

#include <iostream>

void test_3sum(){
    using std::cout;
    using std::endl;

    vector<int> num;

    // [0,0,0]
//    num.push_back(0);
//    num.push_back(0);
//    num.push_back(0);

    // [1,2,-2,-1]
//    num.push_back(1);
//    num.push_back(2);
//    num.push_back(-2);
//    num.push_back(-1);
//    num.push_back(-3);
//    num.push_back(3);

    num.push_back(-1);
    num.push_back(0);
    num.push_back(1);
    num.push_back(2);
    num.push_back(-1);
    num.push_back(-4);

    std::cout<<"Before"<<std::endl;
    for(int i=0; i<num.size(); ++i){
        std::cout<<num[i]<<",";
    }
    std::cout<<std::endl;

    Solution solv;
    vector<vector<int> > data =solv.threeSum(num);

    std::cout<<"After"<<std::endl;
    for(int i=0; i<num.size(); ++i){
        std::cout<<num[i]<<",";
    }
    std::cout<<std::endl;

    std::cout<<"After2"<<std::endl;
    for(int i=0; i<data.size(); ++i){
        for(int j=0; j<data[i].size(); ++j){
            std::cout<<data[i][j]<<",";
        }
        std::cout<<std::endl;
    }

}

#endif // 3SUM_H
