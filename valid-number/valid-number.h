#ifndef VALIDNUMBER_H
#define VALIDNUMBER_H
/* https://oj.leetcode.com/problems/valid-number/
Valid Number Total Accepted: 19071 Total Submissions: 169997 My Submissions Question Solution
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

click to show spoilers.

Hide Tags Math String

*/

/*

 合法的状态组合

 [Space][+/-][Digit][.][Digit][e/E][+/-][Digit][Space]

1.空格+ 数字 + 空格
2.空格+ 点 + 数字 + 空格
3.空格+ 符号 + 数字 +　空格
4.空格+ 符号 + 点 +　数字 + 空格
5.空格+ 数字 + e + 数字 + 空格

state	INVALID   	SPACE	CHAR_SIGN	DIGITAL	CHAR_DOT	CHAR_E	Note
0	-1	0	3	1	2	-1	SPACE
1	-1	8	-1	1	4	5	SPACE+DIGITAL
2	-1	-1	-1	4	-1	-1	SPACE+CHAR_DOT
3	-1	-1	-1	1	2	-1	SPACE+CHAR_SIGN
4	-1	8	-1	4	-1	5	SPACE+DIGITAL+CHAR_DOT
5	-1	-1	6	7	-1	-1	SPACE+DIGITAL+CHAR_DOT+CHAR_E
6	-1	-1	-1	7	-1	-1	SPACE+DIGITAL+CHAR_DOT+CHAR_E+CHAR_SIGN
7	-1	8	-1	7	-1	-1	SPACE+DIGITAL+CHAR_DOT+CHAR_E+DIGITAL
8	-1	8	-1	-1	-1	-1	SPACE+DIGITAL+CHAR_DOT+CHAR_E+DIGITAL+SPACE

*/


class Solution {
public:
    bool isNumber(const char *s) {
        enum CharType{
            INVALID     = 0,
            SPACE       = 1,
            CHAR_SIGN   = 2,
            DIGITAL     = 3,
            CHAR_DOT    = 4,
            CHAR_E      = 5,
            TYPE_COUNT  = 6,
        };
        static char stateTable[][TYPE_COUNT]={
            -1,  0,  3,  1,  2, -1,     // next states for state 0
            -1,  8, -1,  1,  4,  5,     // next states for state 1
            -1, -1, -1,  4, -1, -1,     // next states for state 2
            -1, -1, -1,  1,  2, -1,     // next states for state 3
            -1,  8, -1,  4, -1,  5,     // next states for state 4
            -1, -1,  6,  7, -1, -1,     // next states for state 5
            -1, -1, -1,  7, -1, -1,     // next states for state 6
            -1,  8, -1,  7, -1, -1,     // next states for state 7
            -1,  8, -1, -1, -1, -1,     // next states for state 8
        };
        char state = 0;
        CharType type = INVALID;
        while(s && *s!= '\0'){
            if(*s==' '){
                type = SPACE;
            }else if(*s=='+' || *s=='-'){
                type = CHAR_SIGN;
            }else if(*s=='e' || *s=='E'){
                type = CHAR_E;
            }else if(*s>='0' && *s<='9'){
                type = DIGITAL;
            }else if(*s=='.'){
                type = CHAR_DOT;
            }else{
                type = INVALID;
            }

            state = stateTable[state][type];
            if(state==-1){
                return false;
            }

            ++s;
        }
        return (state==1 || state==4 || state==7 || state==8);
    }
};

#include <iostream>

void test_valid_number(){
    using std::cout;
    using std::endl;


    Solution solv;

    std::cout<<solv.isNumber(" -1.")<<std::endl;
}

#endif // VALIDNUMBER_H
