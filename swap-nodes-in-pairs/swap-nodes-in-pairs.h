#ifndef SWAPNODESINPAIRS_H
#define SWAPNODESINPAIRS_H

#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode pHead = ListNode(0);
        pHead.next = head;

        ListNode* pNow = &pHead;
        ListNode* p1 = 0;
        ListNode* p2 = 0;
        while((p1 = pNow->next) && (p2 = pNow->next->next)){
            pNow->next = p2;
            p1->next = p2->next;
            p2->next = p1;
            pNow = p1;
        }

        return pHead.next;
    }
};

void test_swap_nodes_in_pairs(){
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
        std::cout<<pNow->val<<std::endl;
        pNow = pNow->next;
    }

    Solution sol;
    pNow = sol.swapPairs(pHead->next);

    cout << "After!" << endl;
    while(pNow){
        std::cout<<pNow->val<<std::endl;
        pNow = pNow->next;
    }
}

#endif // SWAPNODESINPAIRS_H
