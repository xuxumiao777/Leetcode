class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int,int> hashmap;
        for(auto num:nums){
            hashmap[num]++;
        }
        for(int i=0;i<hashmap[0];i++){
            nums[i]=0;
        }
        for(int i=hashmap[0];i<hashmap[0]+hashmap[1];i++){
            nums[i]=1;
        }
        for(int i=hashmap[0]+hashmap[1];i<nums.size();i++){
            nums[i]=2;
        }                
    }
};
