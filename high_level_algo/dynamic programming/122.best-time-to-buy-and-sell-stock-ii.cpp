class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size=prices.size();
        vector<vector<int>> state(size,vector<int>(2));
        //init state
        state[0][0]=-prices[0];
        state[0][1]=0;
        for(int i=1;i<size;i++){
            state[i][0]=max(state[i-1][0],state[i-1][1]-prices[i]);
            state[i][1]=max(state[i-1][0]+prices[i],state[i-1][1]);
        }
        return max(state[size-1][0],state[size-1][1]);
    }
};