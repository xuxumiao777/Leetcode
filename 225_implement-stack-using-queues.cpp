class MyStack {
public:
    queue<int> queue1;
    //queue<int> queue2;
    MyStack() {

    }
    
    void push(int x) {
        queue1.push(x);

    }
    
    int pop() {
        int size=queue1.size();
        while(size>1){
            queue1.push(queue1.front());
            queue1.pop();
            size--;
        }
        int front=queue1.front();
        queue1.pop();
        return front;

    }
    
    int top() {
        return queue1.back();

    }
    
    bool empty() {
        if(queue1.empty()){
            return true;
        }
        else{
            return false;
        }

    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
