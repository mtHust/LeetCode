#ifndef SUBSETS_H
#define SUBSETS_H
/* https://oj.leetcode.com/problems/subsets/
Subsets Total Accepted: 33656 Total Submissions: 120033 My Submissions Question Solution 
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
Hide Tags Array Backtracking Bit Manipulation
Have you met this question in a real interview? Yes  No
Discuss

 */

#include <vector>
using std::vector;

#include <algorithm>

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > data;

        std::sort(S.begin(), S.end());

        data.push_back({});

        for(int i=0; i<S.size(); ++i){
            int sz = data.size();
            for(int j=0; j<sz; ++j){
                vector<int> subset=data[j];
                subset.push_back(S[i]);
                data.push_back(subset);
            }
        }
        return data;
    }
};

#include <iostream>

void test_subsets(){
    using std::cout;
    using std::endl;

    vector<int> S;
    S.push_back(1);
    S.push_back(2);
    S.push_back(3);



    std::cout<<"Before"<<std::endl;
    std::cout<<"[";
    for(int i=0; i<S.size(); ++i){
        std::cout<<S[i]<<",";
    }
    std::cout<<"]";
    std::cout<<std::endl;

    Solution sol;
    vector<vector<int> > data = sol.subsets(S);

    std::cout<<"After"<<std::endl;
    std::cout<<"[";
    for(int i=0; i<S.size(); ++i){
        std::cout<<S[i]<<",";
    }
    std::cout<<"]";
    std::cout<<std::endl;

    std::cout<<"After2"<<std::endl;
    for(int i=0; i<data.size(); ++i){
        std::cout<<"[";
        for(int j=0; j<data[i].size(); ++j){
            std::cout<<data[i][j]<<",";
        }
        std::cout<<"]";
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}

#endif // SUBSETS_H
