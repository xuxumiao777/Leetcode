class Solution {
public:
    int robRange(vector<int> &nums,int start,int end){
        vector<int> state(end-start+1,0);
        if(end==start){
            return nums[start];
        }
        state[0]=nums[start];
        state[1]=max(nums[start],nums[start+1]);
        for(int i=start+2;i<end+1;i++){
            state[i-start]=max(state[i-start-2]+nums[i],state[i-start-1]);
        }
        return state[end-start];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int res1=robRange(nums,0,nums.size()-2);
        int res2=robRange(nums,1,nums.size()-1);
        return max(res1,res2);
    }
};