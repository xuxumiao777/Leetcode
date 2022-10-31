class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int size=nums.size();
        int max=-1000;
        int sum_all=0;
        int initial=0;
        for(int i=0;i<size;i++){
            sum_all+=nums[i];
            initial+=i*nums[i];
        }
        max=initial;
        for(int i=1;i<=size;i++){
            initial+=(sum_all-size*nums[size-i]);
            max=max>initial?max:initial;
        }
        return max;
    }
};
