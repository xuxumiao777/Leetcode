class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res=0;
        int c=0;
        int n=nums.size();
        for(int i=0;i<32;i++){
            for(auto &val:nums){
                if(val&1){
                    c++;
                }
                val>>=1;
                
            }
            res+=c*(n-c);
            c=0;

        }
        return res;
    }
};