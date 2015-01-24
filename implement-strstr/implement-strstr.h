#ifndef IMPLEMENTSTRSTR_H
#define IMPLEMENTSTRSTR_H
/* https://oj.leetcode.com/problems/implement-strstr/
Implement strStr() Total Accepted: 34902 Total Submissions: 160029 My Submissions Question Solution
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Update (2014-11-02):
The signature of the function had been updated to return the index instead of the pointer. If you still see your function signature returns a char * or String, please click the reload button  to reset your code definition.

Hide Tags Two Pointers String

Method:


Copyright:
    by maotinghust@gmail.com
    at 2015/01/24
*/

class Solution {
public:
    int strStr(char *haystack, char *needle) {
        if(!haystack || !needle)
            return -1;

        int imain = 0; // main loop
        int iscan = 0; // sub scanner
        while( haystack[imain] && needle[iscan] ){
            if(haystack[imain] == needle[iscan]){
                ++imain;
                ++iscan;
            }else{
                imain = imain - iscan + 1;   // back to the next main loop
                iscan = 0;
            }
        }

        // when needle[iscan]=='\0' then found else not found
        return needle[iscan] ?  -1 : (imain-iscan);
    }
};

#include <iostream>
void test_implement_strstr(){
    using std::cout;
    using std::endl;

    Solution solv;

    cout<<solv.strStr("hello world !", "world")<<endl;
}

#endif // IMPLEMENTSTRSTR_H
