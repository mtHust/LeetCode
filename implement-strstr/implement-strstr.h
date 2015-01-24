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

        int i1 = 0; // main loop
        int i2 = 0; // sub scanner
        while( haystack[i1] && needle[i2] ){
            if(haystack[i1] == needle[i2]){
                ++i1;
                ++i2;
            }else{
                i1 = i1 - i2 + 1;
                i2 = 0;
            }
        }

        return needle[i2] ?  -1 : (i1-i2);
    }
};

#endif // IMPLEMENTSTRSTR_H
