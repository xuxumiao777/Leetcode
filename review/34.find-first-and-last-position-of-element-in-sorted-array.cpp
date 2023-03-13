class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        int mid=0;
        if(nums.size()==0){
            return {-1,-1};
        }
        while(left<=right){
            mid=(left+right+1)/2;
            if(nums[mid]==target){
                break;
            }
            else if(nums[mid]<target){
                left=mid+1;
            }
            else if(nums[mid]>target){
                right=mid-1;
            }
        }
        cout<<mid;
        if(nums[mid]!=target){
            return {-1,-1};
        }
        else{
            //中心扩展
            left=mid;
            right=mid;
            while(left>=0&&nums[left]==target){
                left--;
            }
            while(right<=nums.size()-1&&nums[right]==target){
                right++;
            }
            return {left+1,right-1};
        }
    }
};