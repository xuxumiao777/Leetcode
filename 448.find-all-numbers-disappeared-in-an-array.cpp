class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        unordered_map<int,int> hashmap;
        for(auto num:nums){
            hashmap[num]++;
        }
        for(int i=1;i<=nums.size();i++){
            if(hashmap[i]==0){
                result.push_back(i);
            }
        }
        return result;
    }
};