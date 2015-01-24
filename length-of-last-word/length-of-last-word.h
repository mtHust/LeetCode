#ifndef LENGTHOFLASTWORD_H
#define LENGTHOFLASTWORD_H
/* https://oj.leetcode.com/problems/length-of-last-word/
Length of Last Word Total Accepted: 31854 Total Submissions: 110434 My Submissions Question Solution
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5.

Hide Tags String

*/

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int nlen = 0;
        int state = 0;
        int type = 0;

        // state change table
        // type: 0--space; 1--else;
        int stateTable[][2]={
            0, 1,
            2, 1,
            2, 3,
            2, 1,
        };

        while(s && (*s)!='\0' ){

            if((*s)==' '){
                type=0;
            }else{
                type=1;
            }

            state = stateTable[state][type];

            switch(state){
                case 0: // begin with space
                    nlen=0;
                    break;
                case 1:
                    ++nlen;
                    break;
                case 2: // end with space
                    break;
                case 3:
                    nlen=1;
                    break;
            }

            ++s;
        }

        return nlen;
    }
};

#include <iostream>
void test_length_of_last_word(){
    using std::cout;
    using std::endl;

    Solution solv;
    cout<<solv.lengthOfLastWord("hello world ")<<endl;
}

#endif // LENGTHOFLASTWORD_H
