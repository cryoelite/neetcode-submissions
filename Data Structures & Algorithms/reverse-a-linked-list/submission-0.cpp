/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 // l (val,next = nullptr | *l), if next!=nullptr, then l.next = l, and again and again.
 // Now for us to reverse this, we need to, for each l, copy the l.next, then update the l.next to the previous element, and go on
 // till we reach the last element, and then we simply do this again.
 // And for the first element, we say, that the l.next is nullptr. 

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead{nullptr};
        ListNode* cur{head};
        ListNode* last{nullptr};
        while(cur!=nullptr) {
            ListNode* temp{cur->next};
            cur->next=last;
            last=cur;
            cur=temp;
        }
        newHead=last;


        return newHead;
    }
};
