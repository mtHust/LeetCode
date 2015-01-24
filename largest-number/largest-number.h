#ifndef LARGESTNUMBER_H
#define LARGESTNUMBER_H

/* https://oj.leetcode.com/problems/largest-number/
Largest Number Total Accepted: 4744 Total Submissions: 32093 My Submissions Question Solution
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Hide Tags Sort

[20, 1]
[128, 12]
[12, 128]
[883, 8]
[2, 2313, 2281]

Method:
    Sort
    1. convert number to string
    2. construct the Node objects vector
    3. sort the vector by cmpclass
    4. cmpclass
        compare (str1 + str2) with (str2 + str1)

Copyright:
    by maotinghust@gmail.com
    at 2015/01/23
*/

#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;

class Solution {
public:
    string largestNumber(vector<int> &num) {
        string data;

        vector<Node > nodes;
        for(int i=0; i<num.size(); ++i){
            nodes.push_back(Node(num[i]));
        }

        std::sort(nodes.begin(), nodes.end(), cmpobject);

        for(int inode=0; inode<nodes.size(); ++inode){
            for(int idigit=0; idigit<nodes[inode].digits.size(); ++idigit){
                // the highest==0, ex: [0, 0, 0]
                if(nodes[0].digits[0]=='0'){
                    data.push_back('0');
                    return data;
                }
                data.push_back(nodes[inode].digits[idigit]);
            }
        }

        return data;
    }

private:
    class Node{
    public:
        Node(int num){
            // num>=0
            if(num==0){
                digits.push_back('0');
            }

            int sz = 0;

            while(num>0){
                digits.push_back('0' + num%10);
                num /= 10;
                ++sz;
            }

            // reverse
            for(int i=0; i<sz/2; ++i){
                char c = digits[i];
                digits[i] = digits[sz-1-i];
                digits[sz-1-i] = c;
            }
        }

        string digits;  // digits
    };

    class cmpclass {
    public:
        bool operator() (const Node &node1, const Node & node2) {
            // return node1 > node2
            return (node1.digits + node2.digits) > (node2.digits + node1.digits);
        }
    } cmpobject;
};

#include <iostream>

void test_largest_number(){
    using std::cout;
    using std::endl;

    vector<int> num;

    num.push_back(20);
    num.push_back(1);

    Solution solv;

    std::cout<<solv.largestNumber(num)<<std::endl;

}

#endif // LARGESTNUMBER_H
