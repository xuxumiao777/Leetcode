class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        res[0]=1;
        int temp=1;
        //multiply res from left
        for(int i=1;i<nums.size();i++){
            res[i]=nums[i-1]*temp;
            temp=nums[i-1]*temp;
        }
        temp=1;
        for(int i=nums.size()-1;i>=0;i--){
            res[i]=res[i]*temp;
            temp=nums[i]*temp;
        }
        return res;
        //
    }
};
