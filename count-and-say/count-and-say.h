#ifndef COUNTANDSAY_H
#define COUNTANDSAY_H
 /** https://oj.leetcode.com/problems/count-and-say/
 * Count and Say Total Accepted: 26655 Total Submissions: 103839 My Submissions Question Solution 
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth sequence.
 * 
 * Note: The sequence of integers will be represented as a string.
 * 
 * Hide Tags String
 * Have you met this question in a real interview? Yes  No
 * Discuss
 *
 * 意思就是 第i+1个字符串是第i个字符串的读法
 * 1 "1"
 * 2 "11"
 * 3 "21"
 * 4 "1211"
 * 5 "111221"
 * 6 "312211"
 * 7 "13112221"
 * 8 "1113213211"
 * ......
 * 其实我们可以发现字符串中永远只会出现1,2,3这三个字符，假设第k个字符串中出现了4，那么第k-1个字符串必定有四个相同的字符连续出现，假设这个字符为1，则第k-1个字符串为x1111y。第k-1个字符串是第k-2个字符串的读法，即第k-2个字符串可以读为“x个1,1个1,1个y” 或者“*个x,1个1,1个1,y个*”，这两种读法分别可以合并成“x+1个1,1个y” 和 “*个x，2个1，y个*”，代表的字符串分别是“(x+1)11y” 和 "x21y"，即k-1个字符串为“(x+1)11y” 或 "x21y"，不可能为“x1111y”.
 *
 */
#include <string>
using std::string;
class Solution {
public:
    string countAndSay(int n) {
        if(n<1) return "";
        string data = "1";

        for(int i=2; i<=n; ++i){
            string stmp;

            for(int j=0; j<data.size(); ){
                int cnt = 1;
                int k = j+1;
                while(k<data.size() && data[k]==data[j]){
                    cnt++;
                    k++;
                }

                stmp += '0'+cnt;
                stmp += data[j];
                j = k;
            }

            data = stmp;
        }

        return data;



//        // 下面意思弄成 将i转换成一种对应读法的字符串
//        string data;
//        const int count = 11;
//        const int base = 10;

//        int num[count]={0};
//        int cnt[count]={0};
//        int len = count-1;

//        while(n){
//            int n1 = n/base;
//            int end = n - n1*base;

//            if(end!=num[len]){
//                len--;
//                num[len] = end;
//            }
//            cnt[len]++;
//            n = n1;
//        };

//        for(int i=len; i<count; ++i){
//            if(cnt[i]>0){
//                data += ('0'+cnt[i]);
//                data += ('0'+num[i]);
//            }
//        }

//        return data;
    }
};

#include <iostream>

void test_count_and_say(){
    using std::cout;
    using std::endl;

    Solution solv;
    std::cout<<solv.countAndSay(1)<<std::endl;
    std::cout<<solv.countAndSay(2)<<std::endl;
    std::cout<<solv.countAndSay(3)<<std::endl;
    std::cout<<solv.countAndSay(4)<<std::endl;
    std::cout<<solv.countAndSay(5)<<std::endl;
    std::cout<<solv.countAndSay(6)<<std::endl;
    std::cout<<solv.countAndSay(7)<<std::endl;
    std::cout<<solv.countAndSay(8)<<std::endl;
    std::cout<<solv.countAndSay(9)<<std::endl;
}

#endif // COUNTANDSAY_H
