class Solution {

public:
    
    int numTrees(int n) {
        //initialization
        vector<int> state(n+1,0);
        if(n<=2){
            return n;
        }
        state[0]=1;
        state[1]=1;
        state[2]=2;
        for(int i=3;i<=n;i++){
            for(int j=0;j<i;j++){
                state[i]+=state[j]*state[i-j-1];
            }
        }
        return state[n];
    }
};