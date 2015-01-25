#ifndef WORDSEARCH_H
#define WORDSEARCH_H

/* https://oj.leetcode.com/problems/word-search/
Word Search Total Accepted: 24441 Total Submissions: 123917 My Submissions Question Solution
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
Hide Tags Array Backtracking

*/
#include <vector>
#include <string>
#include <string.h>
using std::vector;
using std::string;

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if(word.empty()){
            return false;
        }
        btraced = board;
        for(int irow=0; irow<btraced.size(); ++irow){
            for(int icol=0; icol<btraced[irow].size(); ++icol){
                btraced[irow][icol] = 0;
            }
        }

        for(int irow=0; irow<board.size(); ++irow){
            for(int icol=0; icol<board[irow].size(); ++icol){
                if(tarce(board, word.c_str(), irow, icol)){
                    return true;
                }
            }
        }

        return false;
    }

private:
    bool tarce(vector<vector<char> > &board, const char* word, int irow, int icol){
        if(!word){
            return true;
        }

        if( board[irow][icol]!= word[0] || btraced[irow][icol]==1){
            return false;
        }

        if(word[1]=='\0'){
            btraced[irow][icol]=1;
            trajectory.push_back(Point(irow, icol));
            return true;
        }

        btraced[irow][icol]=1;

        bool bret = false;

        if(irow<board.size()-1){
            bret |= (tarce(board, word+1, irow+1, icol));
        }

        if(irow>0){
            bret |= (tarce(board, word+1, irow-1, icol));
        }

        if(icol<board[irow].size()-1){
            bret |= (tarce(board, word+1, irow, icol+1));
        }

        if(icol>0){
            bret |= (tarce(board, word+1, irow, icol-1));
        }

        if(bret){
            trajectory.push_back(Point(irow, icol));
            btraced[irow][icol]=1;
        }else{
            btraced[irow][icol]=0;
//            points.pop();
        }

        return bret;
    }

private:
    struct Point{
        int x;
        int y;
        Point(int irow, int icol):
            x(irow), y(icol){

        }
    };

    vector<vector<char> > btraced;
    vector<Point> trajectory;   // the trajectory

};


#include <iostream>

void test_word_search(){
    using std::cout;
    using std::endl;

//    [
//      ["ABCE"],
//      ["SFCS"],
//      ["ADEE"]
//    ]
    vector<vector<char> > board;
    vector<char> sub;
    sub.push_back('A');
    sub.push_back('B');
    sub.push_back('C');
    sub.push_back('E');
    board.push_back(sub);
    sub.clear();
    sub.push_back('S');
    sub.push_back('F');
    sub.push_back('C');
    sub.push_back('S');
    board.push_back(sub);
    sub.clear();
    sub.push_back('A');
    sub.push_back('D');
    sub.push_back('E');
    sub.push_back('E');
    board.push_back(sub);
    string word;
    Solution solv;
    word = "ABCCED";    // -> returns true
//    word = "SEE";    // -> returns true
//    word = "ABCB";    // -> returns false
    std::cout<<solv.exist(board, word)<<std::endl;
}


#endif // WORDSEARCH_H
