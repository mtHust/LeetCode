#ifndef SCRAMBLESTRING_H
#define SCRAMBLESTRING_H
/* https://oj.leetcode.com/problems/scramble-string/
Scramble String Total Accepted: 21127 Total Submissions: 90233 My Submissions Question Solution
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

Hide Tags Dynamic Programming String

*/
#include <vector>
#include <string>
using std::string;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        return judge(s1, s2);
    }

    bool isScramble2(string s1, string s2) {
        int nlen = s1.length();
        if(nlen != s2.length())
            return false;
        int ctable[26];
        for(int i=0; i<26; ++i){
            ctable[i] = 0;
        }
        for(int i=0; i<nlen; ++i){
            ++ctable[s1[i]-'a'];
            --ctable[s2[i]-'a'];
        }
        for(int i=0; i<26; ++i){
            if(ctable[i] != 0)
                return false;
        }

		bool ***bEqual = new bool** [nlen];
        for(int i=0; i<nlen; ++i){
			bEqual[i] = new bool*[nlen];
			for (int j = 0; j<nlen; ++j){
                bEqual[0][i][j] = (s1[i]==s2[j]);
            }
        }


        for(int k=2; k<=nlen; ++k){
            for(int i=nlen-k; i>=0; --i){
                for(int j=nlen-k; j>=0; --j){
                    bool r = false;
                    for(int m=1; m<k; ++m){
                        r =  (bEqual[m-1][i][j] && bEqual[k-m-1][i+m][j+m])
                          || (bEqual[m-1][i][j+k-m] && bEqual[k-m-1][i+m][j]);
                        if(r)
                            break;
                    }
                    bEqual[k-1][i][j] = r;
                }
            }
        }
		bool ret = bEqual[nlen - 1][0][0];
		for (int k = 0; k < nlen; ++k){
			for (int i = 0; i < nlen; ++i){
				delete []bEqual[k][i];
			}
			delete[]bEqual[k];
		}
		delete[]bEqual;
        return ret;
    }
private:
    bool judge(const string& s1, const string& s2) {
        int nlen = s1.length();
        if(nlen != s2.length())
            return false;
        int ctable[26];
        for(int i=0; i<26; ++i){
            ctable[i] = 0;
        }
        for(int i=0; i<nlen; ++i){
            ++ctable[s1[i]-'a'];
            --ctable[s2[i]-'a'];
        }
        for(int i=0; i<26; ++i){
            if(ctable[i] != 0)
                return false;
        }
        string s11, s12, s21, s22;
        for(int ipos=1; ipos<nlen; ++ipos){
            s11 = s1.substr(0, ipos);
            s12 = s1.substr(ipos, nlen-ipos);

            s21 = s2.substr(0, ipos);
            s22 = s2.substr(ipos, nlen-ipos);

            if(judge(s11, s21) && judge(s12, s22)){
                return true;
            }

            s21 = s2.substr(0, nlen-ipos);
            s22 = s2.substr(nlen-ipos, ipos);
            if(judge(s11, s22) && judge(s12, s21)){
                return true;
            }
        }

        return false;
    }
};

void test_scramble_string(){
    Solution solv;
    solv.isScramble("a", "b");
}


#endif // SCRAMBLESTRING_H
