class MyCircularQueue {
public:
    int size;
    int max_size;
    queue<int> circular_queue;
    MyCircularQueue(int k) {
        
        size=0;
        max_size=k;
    }
    
    bool enQueue(int value) {
        if(circular_queue.size()<max_size){
            circular_queue.push(value);
            size++;
            return true;
        }
        else{
            return false;
        }
    }
    
    bool deQueue() {
        if(size>0){
            size--;
            circular_queue.pop();
            return true;
        }
        else{
            return false;
        }

    }
    
    int Front() {
        if(size>0){
            return circular_queue.front();
        }
        else{
            return -1;
        }
        
    }
    
    int Rear() {
        if(size>0){
            return circular_queue.back();
        }
        else{
            return -1;
        }
    }
    
    bool isEmpty() {
        if(size==0){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool isFull() {
        if(size==max_size){
            return true;
        }
        else{
            return false;
        }
    }
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
