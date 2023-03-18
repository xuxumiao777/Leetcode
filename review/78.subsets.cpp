class Solution {
public:
    vector<vector<int>> res;
    void backtracking(vector<int>& nums, vector<int>& cur, int start){
        res.push_back(cur);
        for(int i=start; i<nums.size(); i++){
            cur.push_back(nums[i]);
            backtracking(nums,cur,i+1);
            cur.pop_back();
        }
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        backtracking(nums, cur, 0);
        return res;
    }
};