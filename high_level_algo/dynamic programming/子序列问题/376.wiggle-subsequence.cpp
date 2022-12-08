class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        //state[x][0] 代表的是作为高位
        //state[x][1] 代表的是作为低位
        vector<vector<int>> state(nums.size(),{1,1});
        if(nums.size()<=1){
            return nums.size();
        }
        int res=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                state[i][0]=max(state[i-1][1]+1,state[i-1][0]);
            }
            if(nums[i]<nums[i-1]){
                state[i][1]=max(state[i-1][0]+1,state[i-1][1]);
            }
            if(nums[i]==nums[i-1]){
                state[i][0]=state[i-1][0];
                state[i][1]=state[i-1][1];
            }
            res=max(max(state[i][0],state[i][1]),res);
        }
        return res;

    }
};