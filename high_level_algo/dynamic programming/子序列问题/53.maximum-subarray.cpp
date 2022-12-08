class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size=nums.size();
        vector<int> state(size+1,0);
        state[0]=0;
        int res=INT_MIN;
        for(int i=1;i<=size;i++){
            state[i]=max(state[i-1]+nums[i-1],nums[i-1]);
            //cout<<state[i];
            res=max(res,state[i]);
        }
        return res;
    }
};