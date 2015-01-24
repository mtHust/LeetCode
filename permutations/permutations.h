#ifndef PERMUTATIONS_H
#define PERMUTATIONS_H
/* https://oj.leetcode.com/problems/permutations/
Permutations Total Accepted: 37127 Total Submissions: 117532 My Submissions Question Solution
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

Hide Tags Backtracking

Method:
    1. note that there is no repetition in the niput vector
    2. recursion getpermute(num, len, data)
            to getpermute(num, len-1, data)
                then the len-th data is make up by
                exchange the len-1-th element with the len-1-th data

            when len==1 we get the subset num[1, 2, ..., num]


Copyright:
    by maotinghust@gmail.com
    at 2015/01/24
*/
#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > data;

        getpermute(num, num.size(), data);

        return data;
    }

private:
    void getpermute(vector<int> &num, int len, vector<vector<int> > &data){
        if(len==1){
            data.push_back(num);
            return ;
        }

        getpermute(num, len - 1, data);

        int sz = data.size();
        for(int irow=0; irow<sz; ++irow){
            for(int icol=0; icol<len-1; ++icol){

                vector<int> sub = data[irow];

                std::swap(sub[len-1], sub[icol]);

                data.push_back(sub);
            }
        }

    }
};

#include <iostream>

void test_permutations(){
    using std::cout;
    using std::endl;

    Solution solv;

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);

    vector<vector<int> > data=solv.permute(nums);
    cout<<"["<<endl;
    for(int irow=0; irow<data.size(); ++irow){
        cout<<" [";
        for(int icol=0; icol<data[irow].size(); ++icol){
            cout<<data[irow][icol]<<" ";
        }
        cout<<"]"<<endl;
    }
    cout<<"]"<<endl;
}

#endif // PERMUTATIONS_H
