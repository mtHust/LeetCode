#ifndef REMOVENTHNODEFROMENDOFLIST_H
#define REMOVENTHNODEFROMENDOFLIST_H
/**
 * Remove Nth Node From End of List Total Accepted: 33459 Total Submissions: 116779 My Submissions Question Solution
 * Given a linked list, remove the nth node from the end of list and return its head.
 * 
 * For example,
 * 
 *    Given linked list: 1->2->3->4->5, and n = 2.
 * 
 *    After removing the second node from the end, the linked list becomes 1->2->3->5.
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass.
 * 
 * Hide Tags Linked List Two Pointers
 */

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(0) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode* pFast = head;
        ListNode* pSlow = head;
        int i=0;
        while( i<n && pFast){
            pFast = pFast->next;
            ++i;
        }
        if(!pFast){
            if(i<n){
                return head;
            }else{
                return head->next;
            }
        }

        while(pFast->next){
            pFast = pFast->next;
            pSlow = pSlow->next;
        }

        pSlow->next = pSlow->next->next;

        return head;
    }
};
#include <iostream>
void test_remove_nth_node_from_end_of_list(){
    ListNode *head = new ListNode(0);
    ListNode *pHead = head;
    ListNode *pNow = head;
    for(int i=1; i<6; ++i){
        ListNode *pNew = new ListNode(i);
        pNow->next = pNew;
        pNow = pNew;
    }

    using std::cout;
    using std::endl;
    cout << "Before!" << endl;
    pNow = pHead;
    while(pNow){
        std::cout<<pNow->val<<"-->";
        pNow = pNow->next;
    }
    std::cout<<std::endl;

    Solution solv;
    int n = 1;
    ListNode *pNow2 = solv.removeNthFromEnd(pHead, n);

    cout << "After!" << endl;
    while(pNow2){
        std::cout<<pNow2->val<<"-->";
        pNow2 = pNow2->next;
    }
    std::cout<<std::endl;
}

#endif // REMOVENTHNODEFROMENDOFLIST_H
