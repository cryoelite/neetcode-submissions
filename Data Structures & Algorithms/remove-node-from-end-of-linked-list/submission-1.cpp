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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        using LN= ListNode*;

        if(!head->next) {
            return nullptr;
        }
        LN new_head{new ListNode()};

        new_head->next=head;
        LN l{new_head};
        LN r{head};


        for(int i{0}; i<n; ++i){
            r=r->next;
        }

        while(r!=nullptr){
            r=r->next;
            l=l->next;
        } //l->next is the element we have to remove

        l->next=l->next->next;
        
        return new_head->next;
    }
};
