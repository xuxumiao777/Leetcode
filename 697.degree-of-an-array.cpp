class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int max_size=nums.size(); 
        unordered_map<int,int> hashmap;
        int highest_freq=0;
        int result=50000;
        if(max_size==1){
            return 1;
        }
        if(max_size==0){
            return 0;
        }
        for(auto num:nums){
            hashmap[num]++;
            highest_freq=max(highest_freq,hashmap[num]);
        }
        cout<<highest_freq<<endl;
        int temp;
        for(int i=0;i<max_size;i++){
            if(hashmap[nums[i]]==highest_freq){
                temp=nums[i];
                hashmap[nums[i]]=0;

                for(int j=max_size-1;j>i;j--){
                    if(nums[j]==temp){
                        result=min(result,j-i+1);
                        break;
                    }
                }
            }
        }
        if(result==50000){
            result=1;
        }
        return result;
    }
};
