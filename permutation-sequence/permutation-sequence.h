#ifndef PERMUTATIONSEQUENCE_H
#define PERMUTATIONSEQUENCE_H
/* https://oj.leetcode.com/problems/permutation-sequence/
Permutation Sequence Total Accepted: 20989 Total Submissions: 93632 My Submissions Question Solution
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.

Hide Tags Backtracking Math

*/

#include <string>
using std::string;

class Solution {
public:
    string getPermutation(int n, int k) {
        string data;
        data.resize(n);
        int nums[n];
        int facts[n];
        nums[0] = 1;
        facts[0] = 1;
        for(int i=1; i<n; ++i){
            nums[i] = nums[i-1]+1;
            facts[i] = facts[i-1]*i;
        }

        k = k - 1; // here k = 1,2,...,n!

        for(int i=0; i<n; ++i){
            int sel = k / facts[n-1-i];

            data[i] = '0' + nums[sel];

            for(int j=sel; j<n-i-1; j++)
                nums[j] = nums[j+1];

            k -= sel * facts[n-1-i];
        }

        return data;
    }
};

#include <iostream>
void test_permutation_sequence(){
    using std::cout;
    using std::endl;

    Solution solv;
    cout<<solv.getPermutation(1, 1)<<endl;

    cout<<solv.getPermutation(2, 2)<<endl;

    cout<<solv.getPermutation(4, 1)<<endl;
    cout<<solv.getPermutation(4, 2)<<endl;
    cout<<solv.getPermutation(4, 3)<<endl;
    cout<<solv.getPermutation(4, 4)<<endl;
    cout<<solv.getPermutation(4, 5)<<endl;
    cout<<solv.getPermutation(4, 6)<<endl;
    cout<<solv.getPermutation(4, 7)<<endl;
    cout<<solv.getPermutation(4, 8)<<endl;
}

#endif // PERMUTATIONSEQUENCE_H
