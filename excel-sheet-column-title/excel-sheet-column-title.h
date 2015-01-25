#ifndef EXCELSHEETCOLUMNTITLE_H
#define EXCELSHEETCOLUMNTITLE_H
/* https://oj.leetcode.com/problems/excel-sheet-column-title/
Excel Sheet Column Title Total Accepted: 6978 Total Submissions: 40356 My Submissions Question Solution
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB
Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases.

Hide Tags Math

*/
#include <string>
using std::string;

class Solution {
public:
    string convertToTitle(int n) {
        string s;

        while(n>0){
            n -= 1;

            int a = n / 26;
            int r = n - a*26;

            char c = 'A' + r;

            s = c + s;

            n = a;
        }

        return s;
    }
};

#include <iostream>
void test_excel_sheet_column_title(){
    using std::cout;
    using std::endl;

    Solution solv;

    std::cout<<solv.convertToTitle(1)<<std::endl;
    std::cout<<solv.convertToTitle(26)<<std::endl;
    std::cout<<solv.convertToTitle(27)<<std::endl;
    std::cout<<solv.convertToTitle(703)<<std::endl;
}

#endif // EXCELSHEETCOLUMNTITLE_H
