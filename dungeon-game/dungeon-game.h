#ifndef DUNGEONGAME_H
#define DUNGEONGAME_H
/* https://oj.leetcode.com/problems/dungeon-game/
Dungeon Game Total Accepted: 3251 Total Submissions: 19686 My Submissions Question Solution
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.


Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.

-2 (K)	-3	3
-5	-10 1
10	30	-5 (P)

Notes:

The knight's health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
Credits:
Special thanks to @stellari for adding this problem and creating all test cases.

Hide Tags Dynamic Programming Binary Search

*/

#include <iostream>
#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int nrow = dungeon.size();
        if(nrow==0)
            return 0;
        int ncol = dungeon[0].size();
        if(ncol==0)
            return 0;

        vector<vector<int> > health = dungeon;

        health[nrow-1][ncol-1] = std::max(0-dungeon[nrow-1][ncol-1], 0);

        for(int icol=ncol-2; icol>=0; --icol){
            health[nrow-1][icol] = std::max(health[nrow-1][icol+1] - dungeon[nrow-1][icol], 0);
        }
        for(int irow=nrow-2; irow>=0; --irow){
            health[irow][ncol-1] = std::max( health[irow+1][ncol-1] - dungeon[irow][ncol-1], 0);
        }

        for(int irow=nrow-2; irow>=0; --irow){
            for(int icol=ncol-2; icol>=0; --icol){
                health[irow][icol] = std::max(std::min(health[irow+1][icol], health[irow][icol+1])-dungeon[irow][icol], 0);
            }
        }

        // test path
        std::cout<<"["<<std::endl;
        for(int irow=0; irow<nrow; ++irow){
            std::cout<<" [";
            for(int icol=0; icol<ncol; ++icol){
                std::cout<<health[irow][icol]<<" ";
            }
            std::cout<<" ]"<<std::endl;
        }
        std::cout<<"]"<<std::endl;



        return health[0][0]+1;
    }
};


void test_dungeon_game(){
    using std::cout;
    using std::endl;

    Solution solv;
// [[3,0,-3],[-3,-2,-2],[3,1,-3]]
// [[1,2,1],[-2,-3,-3],[3,2,-2]]
    vector<vector<int> > dungeon;
    vector<int> subset;
    subset.clear();
    subset.push_back(1);
    subset.push_back(2);
    subset.push_back(1);
    dungeon.push_back(subset);
    subset.clear();
    subset.push_back(-2);
    subset.push_back(-3);
    subset.push_back(-3);
    dungeon.push_back(subset);
    subset.clear();
    subset.push_back(3);
    subset.push_back(2);
    subset.push_back(-2);
    dungeon.push_back(subset);


    cout<<"Before"<<endl;
    cout<<"["<<endl;
    for(int irow=0; irow<dungeon.size(); ++irow){
        cout<<" [";
        for(int icol=0; icol<dungeon[0].size(); ++icol){
            cout<<" "<<dungeon[irow][icol]<<" ";
        }
        cout<<" ]"<<endl;
    }
    cout<<"]"<<endl;

    cout<<solv.calculateMinimumHP(dungeon)<<endl;

    cout<<"After"<<endl;
    cout<<"["<<endl;
    for(int irow=0; irow<dungeon.size(); ++irow){
        cout<<" [";
        for(int icol=0; icol<dungeon[0].size(); ++icol){
            cout<<" "<<dungeon[irow][icol]<<" ";
        }
        cout<<" ]"<<endl;
    }
    cout<<"]"<<endl;

}

#endif // DUNGEONGAME_H
