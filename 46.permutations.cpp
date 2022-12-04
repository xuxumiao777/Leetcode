class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    void backtracking(vector<int> &nums,vector<int> &used){
        if(path.size()==nums.size()){
            res.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]==1){
                continue;
            }
            used[i]=1;
            path.push_back(nums[i]);
            backtracking(nums,used);
            path.pop_back();
            used[i]=0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> used(nums.size(),0);
        backtracking(nums,used);
        return res;
    }
};
