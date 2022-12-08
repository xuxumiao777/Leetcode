class Solution {
public:
    int integerBreak(int n) {
        vector<int> state(n+1,0);
        //initialization
        state[2]=1;
        //state[3]
        if(n==2){
            return state[2];
        }
        if(n==3){
            return 2;
        }
        state[3]=2;
        for(int i=3;i<=n;i++){
            for(int j=2;j<=i;j++){
                //int temp=max(j*state[i-j],j*(i-j));
                state[i]=max(state[i],max(j*state[i-j],j*(i-j)));
            }
        }
        return state[n];

    }
};