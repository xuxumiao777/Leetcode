class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string ans = to_string(nums[0]);
        int n = nums.size();
        if (n > 1) ans += '/';
        if (n > 2) ans += '(';
        for (int i = 1; i < n - 1; i ++ ) {
            ans += to_string(nums[i]) + '/';
        }
        if (n > 1) ans += to_string(nums[n - 1]);
        if (n > 2) ans += ')';
        return ans;
    }
};