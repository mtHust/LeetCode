#ifndef TRIANGLE_H
#define TRIANGLE_H
/* https://oj.leetcode.com/problems/triangle/
Triangle Total Accepted: 29494 Total Submissions: 109556 My Submissions Question Solution
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

Hide Tags Array Dynamic Programming

*/

#include <vector>
using std::vector;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int nrow = triangle.size();
        if(nrow==0)
            return 0;
        if(triangle[0].empty())
            return 0;


        for(int irow=1; irow<nrow; ++irow){
            triangle[irow][0] += triangle[irow-1][0];
            for(int icol=1; icol<irow; ++icol){
                triangle[irow][icol] += min(triangle[irow-1][icol-1], triangle[irow-1][icol]);
            }
            triangle[irow][irow] += triangle[irow-1][irow-1];
        }
        int min = triangle[nrow-1][0];
        for(int icol=0; icol<triangle[nrow-1].size(); ++icol){
            if(min>triangle[nrow-1][icol]){
                min = triangle[nrow-1][icol];
            }
        }

        return min;
    }
};

#endif // TRIANGLE_H
