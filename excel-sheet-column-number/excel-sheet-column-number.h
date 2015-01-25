#ifndef EXCELSHEETCOLUMNNUMBER_H
#define EXCELSHEETCOLUMNNUMBER_H

/* https://oj.leetcode.com/problems/excel-sheet-column-number/
Excel Sheet Column Number Total Accepted: 5245 Total Submissions: 12819 My Submissions Question Solution
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28
Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Hide Tags Math

*/

#include <string>
using std::string;

class Solution {
public:
    int titleToNumber(string s) {
        int num = 0;

        for(int i=0; i<s.length(); ++i){
            num = num*26 + (s[i] - 'A' + 1);
        }

        return num;
    }
};

#include <iostream>
void test_excel_sheet_column_number(){
    using std::cout;
    using std::endl;

    Solution solv;

    std::cout<<solv.titleToNumber("A")<<std::endl;
    std::cout<<solv.titleToNumber("Z")<<std::endl;
    std::cout<<solv.titleToNumber("AA")<<std::endl;
    std::cout<<solv.titleToNumber("AAA")<<std::endl;
}

#endif // EXCELSHEETCOLUMNNUMBER_H
