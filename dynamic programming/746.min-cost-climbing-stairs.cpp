class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size=cost.size();
        vector<int> state(size+1,0);
        for(int i=2;i<=size;i++){
            state[i]=min(state[i-2]+cost[i-2],state[i-1]+cost[i-1]);
        }
        return state[size];
    }
};