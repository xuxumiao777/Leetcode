class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(auto num:nums){
            sum+=num;
        }
        int weight=(target+sum)/2;
        if((target+sum)%2!=0){
            return 0;
        }
        if(nums.size()==1){
            if(nums[0]==target||nums[0]==-target){
                return true;
            }
            else{
                return false;
            }
        }
        vector<int> state(weight+1,0);
        state[0]=1;
        for(int i=0;i<nums.size();i++){
            for(int j=weight;j>=0;j--){
                if(nums[i]<=j){
                    state[j]=state[j]+state[j-nums[i]];
                    
                }
            }

        }
        return state[weight];
    }
};