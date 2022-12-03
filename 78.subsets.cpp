class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    void backtracking(vector<int> &nums,int startindex){
        if(startindex>=nums.size()){
            return;
        }
        for(int i=startindex;i<nums.size();i++){
            path.push_back(nums[i]);
            res.push_back(path);
            backtracking(nums,i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums,0);
        res.push_back({});
        return res;
    }
};
