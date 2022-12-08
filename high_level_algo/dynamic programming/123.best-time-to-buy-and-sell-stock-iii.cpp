class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size=prices.size();
        vector<vector<int>> state(size,vector<int>(5));
        //init
        //0 means no operation;1 means first time purchase;2 means first time sell;
        //3 means second time purchase;4 means second time sell;
        state[0][0]=0;
        state[0][1]=-prices[0];
        state[0][2]=0;
        state[0][3]=-prices[0];
        state[0][4]=0;
        for(int i=1;i<size;i++){
            //state[i][0]=max(state[i-1][4],max(state[i-1][0],state[i-1][2]));
            state[i][1]=max(state[i-1][0]-prices[i],state[i-1][1]);
            state[i][2]=max(state[i-1][1]+prices[i],state[i-1][2]);
            state[i][3]=max(state[i-1][2]-prices[i],state[i-1][3]);
            state[i][4]=max(state[i-1][3]+prices[i],state[i-1][4]);
        }
        int res=state[size-1][0];
        for(int i=1;i<5;i++){
            res=max(res,state[size-1][i]);
        }
        return res;        
    }
};