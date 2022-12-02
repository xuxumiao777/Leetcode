class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size=nums.size();
        unordered_map<int,int> hashmap;
        for(auto num:nums){
            hashmap[num]++;
            if(hashmap[num]>size/2){
                return num;
            }
        }
        return 0;
    }
};
