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
    bool hasCycle(ListNode* head) {
        ListNode* slow{head};
        ListNode* fast{head};

        while (fast != nullptr && fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;  // Doing this first because at start slow is at fast.
            slow = slow->next;        // This doesn't need to be checked
            // as fast has already covered it (and checked it for null).
            if (fast == slow) {
                return true;
            }
        }

        return false;
    }
};
