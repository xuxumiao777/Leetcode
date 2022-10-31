class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size=prices.size();
        int max_profit=0;
        int prev;
        int price_buy=prices[0];
        for(prev=0;prev<size-1;prev++){
            if(prices[prev+1]<=prices[prev]){
                //sale the stock
                max_profit+=prices[prev]-price_buy;
                price_buy=prices[prev+1];
            }
        }
        if(prices[size-1]>price_buy){
            max_profit+=prices[size-1]-price_buy;
        }

        return max_profit;


    }
};