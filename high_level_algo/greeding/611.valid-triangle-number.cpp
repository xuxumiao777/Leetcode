class Solution {
public:

    int triangleNumber(vector<int>& nums) {
        
        if(nums.size()<3){
            return 0;
        }
        int res=0;
        sort(nums.begin(),nums.end());
        //cout<<nums[0]<<endl;
        for(int i=0;i<nums.size()-2;i++){
            for(int j=i+1;j<nums.size()-1;j++){
                int left = j + 1, right = nums.size() - 1, k = j;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (nums[mid] < nums[i] + nums[j]) {
                        k = mid;
                        left = mid + 1;
                    }
                    else {
                        right = mid - 1;
                    }
                }
                res += k - j;
            }
        }
        return res;
    }
};