#include <unordered_map>
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node *copyRandomList(Node *head) {
        if (!head) {
            return nullptr;
        }
        unordered_map<Node *, Node *> temp{};
        Node *l{head};
        while (l != nullptr) {
            temp.insert({
                l, new Node(l->val)
            });
            l=l->next;
        }

        l=head;
        while (l!=nullptr) {
            Node* cur{temp[l]};
            cur->next=temp[l->next];
            cur->random=temp[l->random];
            l=l->next;
        }

        return temp[head];
    }
};
