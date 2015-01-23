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

[128, 12]
[12, 128]
[883, 8]
[2, 2313, 2281]

Method:
    1. convert number to string
    2. construct the Node objects vector
    3. sort the vector by cmpclass
    4. cmpclass
        1)
        str1 = strSame + strDiff1;
        str2 = strSame + strDiff2;
        samply compare strDiff1 with strDiff2
        2)
        str1 = strSame + strDiff;
        str2 = strSame;
        compare (strSame + strDiff) with (strDiff + strSame)

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
            for(int idigit=nodes[inode].digits.size()-1; idigit>=0; --idigit){
                if(nodes[0].digits[nodes[0].digits.size()-1]=='0'){
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

            while(num>0){
                digits.push_back('0' + num%10);
                num /= 10;
            }
        }

        string digits;  // digits, reversed
    };

    class cmpclass {
    public:
        bool operator() (const Node &node1, const Node & node2) {
            // return node1 > node2
            string strSame;
            string strDiff;
            for(int i1=node1.digits.size()-1, i2=node2.digits.size()-1;
                i1>=0 && i2>=0; --i1, --i2){
                if(node1.digits[i1] < node2.digits[i2]){
                    return false;
                }else if(node1.digits[i1] > node2.digits[i2]){
                    return true;
                }else{
                    if(i1==0 && i2==0)
                        return false;

                    strSame.push_back(node1.digits[i1]);

                    if(i1==0){
                        for(int j2=i2-1; j2>=0; --j2){
                            strDiff.push_back(node2.digits[j2]);
                        }

                        return (strSame+strDiff) > (strDiff+strSame);
                    }

                    if(i2==0){
                        for(int j1=i1-1; j1>=0; --j1){
                            strDiff.push_back(node1.digits[j1]);
                        }

                        return (strSame+strDiff) < (strDiff+strSame);
                    }
                }
            }

            return true;
        }
    } cmpobject;
};

#include <iostream>

void test_largest_number(){
    using std::cout;
    using std::endl;

    vector<int> num;

    num.push_back(12);
    num.push_back(128);

    Solution solv;

    std::cout<<solv.largestNumber(num)<<std::endl;

}

#endif // LARGESTNUMBER_H
