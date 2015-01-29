#ifndef ADDTWONUMBERS_H
#define ADDTWONUMBERS_H
/* https://oj.leetcode.com/problems/add-two-numbers/
Add Two Numbers Total Accepted: 38832 Total Submissions: 170927 My Submissions Question Solution
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

Hide Tags Linked List Math

*/

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *pHead = 0;
        ListNode *pTail = 0;
        int sum = 0;
        bool carray = 0;

        ListNode *p1 = l1, *p2 = l2;
        while(p1!=0 || p2!=0)
        {
            sum = carray;
            if(p1!=0)
            {
                sum += p1->val;
                p1 = p1->next;
            }

            if(p2!=0)
            {
                sum += p2->val;
                p2 = p2->next;
            }

            carray = sum>9;

            if(carray)
            {
                sum = sum-10;
            }

            appendLast(pHead, pTail, sum);
        }
        if(carray)
        {
            appendLast(pHead, pTail, carray);
        }

        return pHead;
    }

    ListNode* appendLast(ListNode *&pHead, ListNode *& pTail, int val)
    {
        ListNode * pNode = new ListNode(val);

        if(pHead==0)
        {
            pHead = pNode;
            pTail = pHead;
        }
        else
        {
            pTail->next = pNode;
            pTail = pNode;
        }

        return pHead;
    }

};

void test_add_two_numbers(){
    Solution solv;
    solv.addTwoNumbers(0, 0);
}

#endif // ADDTWONUMBERS_H
