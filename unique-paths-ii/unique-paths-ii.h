#ifndef UNIQUEPATHSII_H
#define UNIQUEPATHSII_H
/* https://oj.leetcode.com/problems/unique-paths-ii/
Unique Paths II Total Accepted: 24909 Total Submissions: 89169 My Submissions Question Solution
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.

Hide Tags Array Dynamic Programming

*/

#include <vector>
using std::vector;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int nrow = obstacleGrid.size();
        int ncol = obstacleGrid[0].size();
        if(nrow==0 || ncol==0){
            return 0;
        }

        for(int icol=0; icol<ncol; ++icol){
            if(obstacleGrid[0][icol]==1){
                while(icol<ncol){
                    obstacleGrid[0][icol] = 1;
                    ++icol;
                }
                break;
            }else{
                obstacleGrid[0][icol] = -1;
            }
        }

        for(int irow=0; irow<nrow; ++irow){
            if(obstacleGrid[irow][0]==1){
                while(irow<nrow){
                    obstacleGrid[irow][0] = 1;
                    ++irow;
                }
                break;
            }else{
                obstacleGrid[irow][0] = -1;
            }
        }

        for(int irow=1; irow<nrow; ++irow){
            for(int icol=1; icol<ncol; ++icol){
                if(obstacleGrid[irow][icol]<=0){
                    if(obstacleGrid[irow-1][icol]==1 && obstacleGrid[irow][icol-1]==1){
                        obstacleGrid[irow][icol] = 1;
                        continue;
                    }
                    if(obstacleGrid[irow-1][icol]!=1){
                        obstacleGrid[irow][icol] += obstacleGrid[irow-1][icol];
                    }
                    if(obstacleGrid[irow][icol-1]!=1){
                        obstacleGrid[irow][icol] += obstacleGrid[irow][icol-1];
                    }
                }
            }
        }
        if(obstacleGrid[nrow-1][ncol-1]==1){
            return 0;
        }
        return -obstacleGrid[nrow-1][ncol-1];
    }
};

void test_unique_paths_ii(){
    vector<vector<int> > obstacleGrid;
    vector<int> sub;
    sub.push_back(1);
    sub.push_back(0);
    obstacleGrid.push_back(sub);

    Solution solv;
    solv.uniquePathsWithObstacles(obstacleGrid);
}

#endif // UNIQUEPATHSII_H
