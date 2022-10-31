class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hashmap;
        for(auto a:nums){
            hashmap.insert(a);
        }
        return hashmap.size()<nums.size();

    }
};