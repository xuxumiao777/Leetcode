class Solution {
public:
    //complete backpack
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> state(target+1,0);
        state[0]=1;
        for(int j=0;j<=target;j++){
            //state[0]=1;
            for(int i=0;i<nums.size();i++){
                if(j>=nums[i]&&state[j]<INT_MAX-state[j-nums[i]])
                    state[j]+=state[j-nums[i]];
            }
        }
        return state[target];
    }
};