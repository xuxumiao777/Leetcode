class Solution {
public:
    int climbStairs(int n) {
        vector<int> state(45,0);
        state[0]=1;
        state[1]=2;
        for(int i=2;i<n;i++){
            state[i]=state[i-1]+state[i-2];
        }
        return state[n-1];
    }
};