class Solution {
public:
    int reverse(int x) {
        stack<int> q;
        while(x){
            q.push(x%10);
            x=x/10;
        }
        
        long long res=0;
        long long factor=1;
        while(!q.empty()){
            
            res+=factor*q.top();
            q.pop();
            factor*=10;
        }
        if(x<0){
            res=-res;
        }
        if(res>pow(2,31)-1||res<-pow(2,31)){
            return 0;
        }
        return res;
    }
};