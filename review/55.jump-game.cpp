class Solution {
public:
    bool canJump(vector<int>& nums) {
        //第一感觉是动态规划 vector<bool> state 来记录每个格子能否到达下标。
        int size=nums.size();
        vector<bool> state(size,false);
        state[size-1]=true;
        for(int i=size-2;i>=0;i--){
            int num=nums[i];
            for(int j=i;j<=num+i&&j<size;j++){
                if(state[j]==true){
                    state[i]=true;
                    break;
                }
            }
        }
        return state[0];
    }
};