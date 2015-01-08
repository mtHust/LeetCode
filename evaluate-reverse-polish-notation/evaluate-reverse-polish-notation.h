#ifndef EVALUATEREVERSEPOLISHNOTATION_H
#define EVALUATEREVERSEPOLISHNOTATION_H
/* https://oj.leetcode.com/problems/evaluate-reverse-polish-notation/
Evaluate Reverse Polish Notation Total Accepted: 33579 Total Submissions: 165792 My Submissions Question Solution
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
Hide Tags Stack
Have you met this question in a real interview? Yes  No
Discuss

*/

#include <string>
#include <vector>
#include <stack>
using std::string;
using std::vector;

#include <stdlib.h>

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        int result = 0;
        int a,b;
        using std::stack;
        stack<int> S;
        S.push(result);
        for(int i=0; i<tokens.size(); ++i){
            switch (tokens[i][0]) {
            case '+':
                a = S.top();
                S.pop();
                b = S.top();
                S.pop();
                result = b + a;
                S.push(result);
                break;
            case '-':
                if(1==tokens[i].size()){
                    a = S.top();
                    S.pop();
                    b = S.top();
                    S.pop();
                    result = b - a;
                    S.push(result);
                }else{
                    S.push(atoi(tokens[i].c_str()));
                }
                break;
            case '*':
                a = S.top();
                S.pop();
                b = S.top();
                S.pop();
                result = b * a;
                S.push(result);
                break;
            case '/':
                a = S.top();
                S.pop();
                b = S.top();
                S.pop();
                result = b / a;
                S.push(result);
                break;
            default:
                S.push(atoi(tokens[i].c_str()));
                break;
            }
        }

        result = S.top();

        return result;
    }
};

#include <iostream>

void test_evaluate_reverse_polish_notation(){
    using std::cout;
    using std::endl;
    vector<string> tokens;

    tokens.push_back("18");

    // ["2", "1", "+", "3", "*"] 9
//    tokens.push_back("2");
//    tokens.push_back("1");
//    tokens.push_back("+");
//    tokens.push_back("3");
//    tokens.push_back("*");

    // ["4", "13", "5", "/", "+"] 6
//    tokens.push_back("4");
//    tokens.push_back("13");
//    tokens.push_back("5");
//    tokens.push_back("/");
//    tokens.push_back("+");

    // ["-1","1","*","-1","+"] -2
//    tokens.push_back("-1");
//    tokens.push_back("1");
//    tokens.push_back("*");
//    tokens.push_back("-1");
//    tokens.push_back("+");

    // ["4","-2","/","2","-3","-","-"] -7
//    tokens.push_back("4");
//    tokens.push_back("-2");
//    tokens.push_back("/");
//    tokens.push_back("2");
//    tokens.push_back("-3");
//    tokens.push_back("-");
//    tokens.push_back("-");

    Solution solv;

    std::cout<<solv.evalRPN(tokens)<<std::endl;
}

#endif // EVALUATEREVERSEPOLISHNOTATION_H
