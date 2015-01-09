#ifndef BINARYTREELEVELORDERTRAVERSAL_H
#define BINARYTREELEVELORDERTRAVERSAL_H
/* https://oj.leetcode.com/problems/binary-tree-level-order-traversal/
Binary Tree Level Order Traversal Total Accepted: 34455 Total Submissions: 115259 My Submissions Question Solution
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

Hide Tags Tree Breadth-first Search

 */

#include <vector>
#include <list>
using std::vector;

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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > data;
        if(!root){
            return data;
        }

        using std::list;
        list<TreeNode* > lst;
        lst.push_back(root);
        while(!lst.empty()){
            vector<int> sub;

            int sz = lst.size();            
            for(int i=0; i<sz; ++i){
                TreeNode* node = lst.front();

                sub.push_back(node->val);

                if(node->left) lst.push_back(node->left);
                if(node->right) lst.push_back(node->right);

                lst.pop_front();
            }

            data.push_back(sub);
        }

        return data;
    }
};

#include <iostream>

void test_binary_tree_level_order_traversal(){
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
    vector<vector<int> > data = sol.levelOrder(pHead);

    std::cout<<"After2"<<std::endl;
    for(int i=0; i<data.size(); ++i){
        std::cout<<"[";
        for(int j=0; j<data[i].size(); ++j){
            std::cout<<data[i][j]<<",";
        }
        std::cout<<"]";
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}

#endif // BINARYTREELEVELORDERTRAVERSAL_H
