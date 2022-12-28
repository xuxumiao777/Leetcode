class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> nums_sorted=nums;
        sort(nums_sorted.begin(),nums_sorted.end());
    
        int left=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=nums_sorted[i]){
                left=i;
                break;
            }
        }
        int right=0;
        for(int j=nums.size()-1;j>=left;j--){
            if(nums[j]!=nums_sorted[j]){
                right=j;
                break;
            }
        }
        if(right==left){
            return 0;
        }
        return right-left+1;
    }
};