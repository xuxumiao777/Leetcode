class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int dates=prices.size();
        vector<vector<int>> state(dates,vector<int>(3,0));
        //init
        //state[0][0]=0;
        state[0][1]=-prices[0];
        //state[0][2]=-1*fee;
        for(int i=1;i<dates;i++){
            state[i][1]=max(state[i-1][2]-prices[i],max(state[i-1][1],state[i-1][0]-prices[i]));
            state[i][2]=max(state[i-1][2],state[i-1][1]+prices[i]-fee);
        }
        //cout<<state[dates-1][1];
        return max(state[dates-1][0],state[dates-1][2]);
    }
};