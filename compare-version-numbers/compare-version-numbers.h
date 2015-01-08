#ifndef COMPAREVERSIONNUMBERS_H
#define COMPAREVERSIONNUMBERS_H
/*  https://oj.leetcode.com/problems/compare-version-numbers/
Compare Version Numbers Total Accepted: 5782 Total Submissions: 39200 My Submissions Question Solution 
Compare two version numbers version1 and version1.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Hide Tags String
 */
#include <string>
using std::string;

class Solution {
public:
    int compareVersion(string version1, string version2) {
		int len1 = version1.length();
		int len2 = version2.length();
		for(int i1=0, i2=0; i1<len1 || i2<len2; ++i1, ++i2){
            int v1 = 0;
			while(version1[i1]!='.' && i1<len1){
                v1 = v1*10 + (version1[i1]-'0');
                ++i1;
			}
            int v2 = 0;
			while(version2[i2]!='.' && i2<len2){
                v2 = v2*10 + (version2[i2]-'0');
                ++i2;
			}
			
            if(v1>v2){
                return 1;
            }else if(v1<v2){
                return -1;
            }
		}
        return 0;
    }
};

#include <iostream>

void test_compare_version_numbers(){
    using std::cout;
    using std::endl;

    Solution solv;
    std::cout<<solv.compareVersion("01", "1")<<std::endl;
}

#endif // COMPAREVERSIONNUMBERS_H
