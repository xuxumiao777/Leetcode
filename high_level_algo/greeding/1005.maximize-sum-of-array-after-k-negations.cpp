#include <iostream>
#include <vector>
 
using namespace std;
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int sum=0;
        for(auto num:nums){
            sum+=num;
        }
        //cout<<sum;
        for(int i=1;i<=k;i++){
            sort(nums.begin(),nums.end());
            nums[0]=-1*nums[0];
            //cout<<nums[0]<<endl;
            sum=sum+2*nums[0];
        }
        return sum;
    }
};