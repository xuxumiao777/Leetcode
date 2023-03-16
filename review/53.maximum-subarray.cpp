class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //第一感觉是动态规划
        int size=nums.size();
        vector<int> state(size+1,0);
        //状态定义是：在选择第i个元素的条件下，[i,size)最大可能出现的数
        for(int i=size-1;i>=0;i--){
            state[i]=max(state[i+1]+nums[i],nums[i]);
        }
        int res=nums[0];
        for(int i=0;i<size;i++){
            res=max(res,state[i]);
        }
        return res;
    }
};