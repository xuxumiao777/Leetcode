class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dates=prices.size();
        vector<vector<int>> state(dates,vector<int>(4,0));
        //state[0][1]=prices[0];
        state[0][2]=-prices[0];
        state[0][3]=-prices[0];
        if(dates==1){
            return 0;
        }
        for(int i=1;i<dates;i++){
            state[i][0]=max(state[i-1][0],state[i-1][1]);
            state[i][1]=max(state[i-1][2]+prices[i],state[i-1][3]+prices[i]);
            state[i][2]=max(state[i-1][2],state[i-1][0]-prices[i]);
            state[i][3]=max(state[i-1][3],state[i-1][2]);
        }
        return max(state[dates-1][0],state[dates-1][1]);
    }
};