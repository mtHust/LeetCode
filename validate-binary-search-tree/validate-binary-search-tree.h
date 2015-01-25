#ifndef VALIDATEBINARYSEARCHTREE_H
#define VALIDATEBINARYSEARCHTREE_H

/* https://oj.leetcode.com/problems/validate-binary-search-tree/
Validate Binary Search Tree Total Accepted: 32892 Total Submissions: 142628 My Submissions Question Solution
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

Hide Tags Tree Depth-first Search

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

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return check(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }
private:
    bool check(TreeNode *root, long long leftVal, long long rightVal){
        if(!root)
            return true;

        if(leftVal >= root->val || rightVal <= root->val){
            return false;
        }

        return ( check(root->left, leftVal,root->val) && check(root->right, root->val, rightVal) );
    }
};

#include <iostream>

void test_validate_binary_search_tree(){
    using std::cout;
    using std::endl;
    // build up TreeNode
    TreeNode* pHead = new TreeNode(0);

    pHead->left = new TreeNode(1);
    pHead->right = new TreeNode(2);

    TreeNode* pNow = pHead;

    pNow = pNow->left;
    pNow->left = new TreeNode(3);
    pNow = pNow->left;
    pNow->left = new TreeNode(4);

    Solution sol;

    std::cout<<sol.isValidBST(pHead)<<std::endl;

}

#endif // VALIDATEBINARYSEARCHTREE_H
