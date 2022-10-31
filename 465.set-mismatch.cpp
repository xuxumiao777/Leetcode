class Solution {
public:

    vector<int> findErrorNums(vector<int>& nums) {
        int max_size=nums.size();
        sort(nums.begin(),nums.end(),less<>());
        vector<int> result(2);
        unordered_map<int,int> hashmap;
        
        //int left=0,right=max_size-1;
        for(int i=0;i<max_size;i++){
            
            hashmap[nums[i]]++;         
        }
        for(int j=1;j<=max_size;j++){
            if(hashmap[j]==0){
                result[1]=j;
               
            }
            if(hashmap[j]==2){
                result[0]=j;

            }
        }
        return result;
    }
};
