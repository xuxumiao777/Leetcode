class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_set<int> hashmap;
        for(auto num:nums1){
            hashmap.insert(num);
        }
        for(auto num2:nums2){
            if(hashmap.count(num2)==1){
                
                hashmap.erase(num2);
                result.push_back(num2);
            }
        }
        return result;

    }
};