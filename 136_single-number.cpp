class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> hashmap;
        for(auto num:nums){
            if(hashmap.count(num)>0){
                hashmap.erase(num);
            }
            else{
                hashmap.insert(num);
            }
        }
        return *hashmap.begin();

    }
};