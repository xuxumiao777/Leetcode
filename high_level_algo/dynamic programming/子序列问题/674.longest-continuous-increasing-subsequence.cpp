class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int len=nums.size();
        vector<int> state(len,1);
        int res=1;
        for(int i=1;i<len;i++){
            if(nums[i]>nums[i-1]){
                state[i]=state[i-1]+1;
            }
            if(state[i]>res){
                res=state[i];
            }
        }
        return res;

    }
};