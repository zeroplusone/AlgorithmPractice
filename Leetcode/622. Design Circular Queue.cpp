class MyCircularQueue {
public:
    
    MyCircularQueue(int k) {
        this->k=k;
        size=0;
        front=nullptr;
        rear=nullptr;
    }
    
    bool enQueue(int value) {
        if(size==k) {
            return false;
        }
        
        if(size==0) {
            front=new ListNode(value);
            rear=front;
        } else {
            ListNode* tmp = rear;
            rear->next=new ListNode(value);
            rear=rear->next;
            rear->last=tmp;
        }
        size++;

        return true;
    }
    
    bool deQueue() {
        if(size==0) {
            return false;
        }
        
        if(size==1) {
            delete(front);
            front=nullptr;
            rear=nullptr;
        } else {
            front = front->next;
            delete(front->last);
            front->last=nullptr;
        }
        size--;
                
        return true;
    }
    
    int Front() {
        return front==nullptr?-1:front->val;
    }
    
    int Rear() {
        return rear==nullptr?-1:rear->val;
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==k;
    }
private:
    static struct ListNode {
        int val;
        ListNode* next;
        ListNode* last;
        ListNode(int val): val(val), next(nullptr), last(nullptr) {};
    };

    ListNode* front, *rear;
    int size;
    int k;
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
