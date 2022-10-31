class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> hashmap;
        for(auto num:nums){
            hashmap[num]++;
        }
        int length=1;
        int max_length=0;
        int j=0;
        for(int i=0;i<nums.size();i++){
            length=1;
            if(hashmap[nums[i]]!=0){
                hashmap[nums[i]]=0;
                j=1;
                while(hashmap[nums[i]+j]!=0){
                    hashmap[nums[i]+j]=0;
                    length++;
                    j++;
                }
                //max_length=max(length,max_length);
                j=-1;
                while(hashmap[nums[i]+j]!=0){
                    hashmap[nums[i]+j]=0;
                    length++;
                    j--;
                }
                max_length=max(length,max_length);                
            }
            
        }
        return max_length;
    }
};
