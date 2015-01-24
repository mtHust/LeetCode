#ifndef MAJORITYELEMENT_H
#define MAJORITYELEMENT_H
/* https://oj.leetcode.com/problems/majority-element/
Majority Element Total Accepted: 14715 Total Submissions: 43225 My Submissions Question Solution
Given an array of size n, find the majority element. The majority element is the element that appears more than [n/2] times.

You may assume that the array is non-empty and the majority element always exist in the array.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Hide Tags Divide and Conquer Array Bit Manipulation

Method:


Copyright:
    by maotinghust@gmail.com
    at 2015/01/24

*/

#include <vector>
using std::vector;

class Solution {
public:
    int majorityElement(vector<int> &num) {
        int ret = 0;    // the majority
        int cnt = 0;    // counts of the majority
        for(int i=0; i<num.size(); ++i){
            if(cnt==0){
                ++cnt;
                ret=num[i];
            }else if(ret==num[i]){
                ++cnt;
            }else{
                --cnt;
            }
        }

        return ret;
    }
};

#include <iostream>

void test_majority_element(){
    using std::cout;
    using std::endl;

    vector<int> num;
    num.push_back(1);
    num.push_back(1);
    num.push_back(2);

    Solution solv;

    cout<<solv.majorityElement(num)<<endl;

}

#endif // MAJORITYELEMENT_H
