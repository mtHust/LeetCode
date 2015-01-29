#ifndef REORDERLIST_H
#define REORDERLIST_H

/* https://oj.leetcode.com/problems/reorder-list/
Reorder List Total Accepted: 29776 Total Submissions: 144613 My Submissions Question Solution
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.

Hide Tags Linked List

*/

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

#include <vector>

class Solution {
public:
    void reorderList(ListNode *head) {
        if(!head)
            return;
        using std::vector;
        vector <ListNode*> vec;

        ListNode* pNow = head;
        while(pNow){
            vec.push_back(pNow);
            pNow = pNow->next;
        }

        pNow = head;
        int sz = vec.size();
		for (int i = 0; i<sz / 2 && pNow; ++i){

            ListNode *p1 = pNow->next;
            ListNode *p2 = vec[sz-1-i];

            p2->next = p1;

            pNow->next = p2;

            pNow = p1;
        }
		if (pNow)
			pNow->next = 0;
    }
};


void test_reorder_list(){
    using std::cout;
    using std::endl;
    // build up ListNode
    ListNode* pHead = new ListNode(0);
    ListNode* pNow = pHead;
    for(int i=1; i<6; ++i){
        ListNode* pNew = new ListNode(i);
        pNew->next = 0;
        pNow->next = pNew;
        pNow = pNew;
    }

    cout << "Before!" << endl;
    pNow = pHead->next;
    while(pNow){
        std::cout<<pNow->val<<",";
        pNow = pNow->next;
    }
    std::cout<<std::endl;

    Solution sol;
    sol.reorderList(pHead->next);
    pNow = pHead->next;

    cout << "After!" << endl;
    while(pNow){
        std::cout<<pNow->val<<",";
        pNow = pNow->next;
    }
    std::cout<<std::endl;
}

#endif // REORDERLIST_H
