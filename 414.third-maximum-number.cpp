class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<>());
        for (int i = 1, num_diff = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) { 
                num_diff++;
                if(num_diff==3){
                    return nums[i];
                }
            }
        }
        return nums[0];
    }
};


