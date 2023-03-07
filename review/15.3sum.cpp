class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int left=0;
        int right=0;
        vector<vector<int>> res;
        vector<int> temp;
        for(int i=0;i<nums.size();i++){
            temp.clear();
            if(nums[i]>0){
                break;
            }
            left=i+1;
            right=nums.size()-1;
            //cout<<left<<endl;
            while(left<right){
                if(nums[i]+nums[left]+nums[right]<0){
                    left++;
                }
                else if(nums[i]+nums[left]+nums[right]>0){
                    right--;
                }
                else{
                    temp.push_back(nums[i]);
                    temp.push_back(nums[left]);
                    temp.push_back(nums[right]);
                    res.push_back(temp);
                    temp.clear();
                    while(left<right&&nums[left]==nums[left+1])
                        left++;
                    while(left<right&&nums[right] == nums[right-1])
                        right--;
                    left++;
                    right--;
                }
            }
            while(i<nums.size()-1&&nums[i]==nums[i+1]){
                i++;
            }
        }
        return res;
    }
};