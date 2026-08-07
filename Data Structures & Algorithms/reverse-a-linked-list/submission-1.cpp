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

class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr) {
            return head;
        }
        ListNode* prev{head};
        ListNode* next{head->next};
        head->next=nullptr;
        while (next != nullptr) {
            ListNode* temp{next->next};
            next->next=prev;
            prev=next;
            next=temp;
        }
        return prev;
    }
};
