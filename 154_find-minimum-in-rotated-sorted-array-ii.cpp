class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        int mid;
        while(left<right){
            mid=left+(right-left)/2;
            if(nums[right]>nums[mid]){
                //the minimum element is in the left half set
                right=mid;
            }
            else if(nums[right]<nums[mid]){
                left=mid+1;
            }
            else if(nums[right]==nums[mid]){
                right--;
            }
        }
        return nums[left];

    }
};