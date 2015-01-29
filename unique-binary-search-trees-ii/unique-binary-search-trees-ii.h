#ifndef UNIQUEBINARYSEARCHTREESII_H
#define UNIQUEBINARYSEARCHTREESII_H

/* https://oj.leetcode.com/problems/unique-binary-search-trees-ii/
Unique Binary Search Trees II Total Accepted: 22922 Total Submissions: 83673 My Submissions Question Solution
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

Hide Tags Tree Dynamic Programming

*/

/**
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#include <vector>
using std::vector;

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        return generate(1, n);
    }
private:
    vector<TreeNode *> generate(int start, int end){
        vector<TreeNode *> data;

        if(start>end){
            data.push_back(0);
            return data;
        }

        for(int i=start; i<=end; ++i){
            vector<TreeNode *> vleft = generate(start, i-1);
            vector<TreeNode *> vright = generate(i+1, end);
            for(int ileft=0; ileft<vleft.size(); ++ileft){
                for(int iright=0; iright<vright.size(); ++iright){
                    TreeNode* pNode = new TreeNode(i);
                    pNode->left = vleft[ileft];
                    pNode->right = vright[iright];
                    data.push_back(pNode);
                }
            }
        }

        return data;
    }

};

void test_unique_binary_search_trees_ii(){

}

#endif // UNIQUEBINARYSEARCHTREESII_H
