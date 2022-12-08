class Solution {
public:
    int numSquares(int n) {
        vector<int> state(n+1,INT_MAX);
        state[0]=0;//1=1*1;
        //cout<<sqrt(5);
        int temp=0;
        for(int i=0;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                temp=sqrt(i);
                if(i==temp*temp){
                    state[i]=1;
                }
                else{
                    state[i]=min(state[i-j*j]+1,state[i]);
                }
            }
            //cout<<state[i];
        }
        return state[n];
    }
};