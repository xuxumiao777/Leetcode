class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> hashmap;
        int element_tosave;
        for(int i=0;i<nums.size();i++){
            element_tosave=target-nums[i];
            if(hashmap.count(element_tosave)>0){
                return {i,hashmap[element_tosave]};
            }
            hashmap[nums[i]]=i;
        }
        return {-1,-1};

    }
};