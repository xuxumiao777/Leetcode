class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> state(amount+1,0);
        state[0]=1;
        for(int i=0;i<coins.size();i++){
            for(int j=coins[i];j<=amount;j++){
                                
                state[j]+=state[j-coins[i]];
              
            }
        }
        return state[amount];
    }
};