#ifndef PASCALSTRIANGLE_H
#define PASCALSTRIANGLE_H

/* https://oj.leetcode.com/problems/pascals-triangle/
Pascal's Triangle Total Accepted: 30954 Total Submissions: 100895 My Submissions Question Solution
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
Hide Tags Array

*/
#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > data(numRows);

        if(numRows<1){
            return data;
        }

        data[0].push_back(1);

        for(int irow=1; irow<numRows; ++irow){
            data[irow] = vector<int > (irow + 1);

            data[irow][0] = 1;
            for(int icol=1; icol<irow; ++icol){
                data[irow][icol] = data[irow-1][icol-1] + data[irow-1][icol];
            }
            data[irow][irow] = 1;
        }

        return data;
    }
};


void test_pascals_triangle(){
    using std::cout;
    using std::endl;

    Solution sol;
    vector<vector<int> > data = sol.generate(5);

    std::cout<<"After"<<std::endl;
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


#endif // PASCALSTRIANGLE_H
