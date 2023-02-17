class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashmap;
        for(auto num:nums){
            hashmap[num]++;
        }
        int res1=-1,res2=-1;
        for(int i=0; i<nums.size(); i++){
            hashmap[nums[i]]--;
            if(hashmap[target-nums[i]]>0){
                res1=i;
                res2=target-nums[i];
                break;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==res2&&i!=res1){
                res2=i;
                break;
            }
        }
        vector<int> res={res1,res2};
        return res;
    }
};