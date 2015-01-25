#ifndef PASCALSTRIANGLEII_H
#define PASCALSTRIANGLEII_H

/* https://oj.leetcode.com/problems/pascals-triangle-ii/
Pascal's Triangle II Total Accepted: 28338 Total Submissions: 94943 My Submissions Question Solution
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?

Hide Tags Array

*/

#include <vector>
using std::vector;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> data(rowIndex+1);
        if(rowIndex<0){
            return data;
        }

        data[0] = 1;

        for(int irow=1; irow<rowIndex+1; ++irow){

            data[0] = 1;
            for(int icol=irow/2; icol>0; --icol){
                data[icol] = data[icol-1] + data[icol];
                data[irow-icol] = data[icol];
            }
            data[irow] = 1;
        }

        return data;
    }
};


void test_pascals_triangle_ii(){
    using std::cout;
    using std::endl;

    Solution sol;
    vector<int> data = sol.getRow(5);

    std::cout<<"After"<<std::endl;
    std::cout<<"[";
    for(int j=0; j<data.size(); ++j){
        std::cout<<data[j]<<",";
    }
    std::cout<<"]";
    std::cout<<std::endl;
}

#endif // PASCALSTRIANGLEII_H
