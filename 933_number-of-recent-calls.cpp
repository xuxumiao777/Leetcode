class RecentCounter {
public:
    int stack[10000];
    int size=0;
    RecentCounter() {

    }
    
    int ping(int t) {
        size++;
        int num=size;
        stack[num-1]=t;
        while(num-1>=0&&t-stack[num-1]<=3000){
            num--;
            
            

        }

        return size-num;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
