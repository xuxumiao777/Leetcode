class Solution {
public:
    int rob(vector<int>& nums) {
        int size=nums.size();
        if(size==1){
            return nums[0];
        }
        vector<int> state(size,0);
        state[0]=nums[0];
        state[1]=max(nums[0],nums[1]);
        for(int i=2;i<size;i++){
            state[i]=max(state[i-2]+nums[i],state[i-1]);
        }
        return state[size-1];
    }
};