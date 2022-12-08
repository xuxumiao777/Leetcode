class Solution {
public
    int lengthOfLIS(vectorint& nums) {
        int size=nums.size();
        vectorint state(size,1);
        int res=1;
        for(int i=1;isize;i++){
            for(int j=0;ji;j++){
                if(nums[i]nums[j]){
                    state[i]=max(state[i],state[j]+1);
                }
            }
            if(state[i]res){
                res=state[i];
            }
        }
        return res;
    }
};