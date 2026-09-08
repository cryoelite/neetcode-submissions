struct LinkedList {
    LinkedList* next;
    LinkedList* prev;
    int val;
    LinkedList() : next(nullptr), prev(nullptr), val(0) {}
    LinkedList(int val) : next(nullptr), prev(nullptr), val(val) {}
};
using LL = LinkedList;
class MyCircularQueue {
    LL front;
    LL rear;

    int k;
    int count;

   public:
    MyCircularQueue(int k) : front(LL()), rear(LL()), k(k), count(0) {
        front.next = &rear;
        rear.prev = &front;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        LL* new_elem{new LL(value)};
        LL* prev{rear.prev};

        rear.prev = new_elem;
        new_elem->next = &rear;
        new_elem->prev = prev;
        prev->next = new_elem;

        ++count;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        LL* next{front.next->next};
        front.next = next;
        next->prev = &front;

        --count;
        return true;
    }

    int Front() { return isEmpty() ? -1 : front.next->val; }

    int Rear() { return isEmpty() ? -1 : rear.prev->val; }

    bool isEmpty() { return !count; }

    bool isFull() { return count == k; }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
