class MyQueue {
public:
    stack<int> stk1;
    stack<int> stk2;
    MyQueue() {

    }
    
    void push(int x) {
        int size=stk2.size();
        while(size){
            int element=stk2.top();
            stk1.push(element);
            stk2.pop();
            size--;
        }
        stk1.push(x);
        size=stk1.size();
        while(size){
            int element=stk1.top();
            stk2.push(element);
            stk1.pop();
            size--;
        }

    }
    
    int pop() {
        int temp=stk2.top();
        stk2.pop();
        return temp;

    }
    
    int peek() {
        return stk2.top();

    }
    
    bool empty() {
        return stk2.empty();

    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
