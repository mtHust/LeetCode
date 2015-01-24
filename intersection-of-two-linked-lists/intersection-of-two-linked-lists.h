#ifndef INTERSECTIONOFTWOLINKEDLISTS_H
#define INTERSECTIONOFTWOLINKEDLISTS_H
/* https://oj.leetcode.com/problems/intersection-of-two-linked-lists/
Intersection of Two Linked Lists Total Accepted: 12681 Total Submissions: 46472 My Submissions Question Solution
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
Credits:
Special thanks to @stellari for adding this problem and creating all test cases.

Hide Tags Linked List

Method:
    1. get length of list A, B
    2. when the last node of A B are not equal return 0
    3. let the longer list go by diff step first
    4. then the two list go ahead together until to the joint

Copyright:
    by maotinghust@gmail.com
    at 2015/01/24
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB){
            return 0;
        }

        // get length of list A
        int lenA = 1;
        ListNode *pA = headA;
        while(pA->next){
            ++lenA;
            pA = pA->next;
        }

        // get length of list B
        int lenB = 1;
        ListNode *pB = headB;
        while(pB->next){
            ++lenB;
            pB = pB->next;
        }

        // when the last node of A B are not equal
        if(pA!=pB){
            return 0;
        }

        // let the longer list go by diff step first
        pA = headA;
        pB = headB;
        int lenD = lenA - lenB;
        if(lenD>0){
            while(lenD){
                pA = pA->next;
                --lenD;
            }
        }else if(lenD<0){
            while(lenD){
                pB = pB->next;
                ++lenD;
            }
        }

        // then the two list go ahead together until to the joint
        while(pA!=pB){
            pA = pA->next;
            pB = pB->next;
        }

        return pA;
    }
};

void test_intersection_of_two_linked_lists(){
    Solution solv;
    solv.getIntersectionNode(0, 0);
}

#endif // INTERSECTIONOFTWOLINKEDLISTS_H
