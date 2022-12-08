class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    int sum=0;
    void backtracking(vector<int> &candidates,int target,int index){
        if(sum>target){
            return;
        }
        if(sum==target){
            res.push_back(path);
            return;
        }
        for(int i=index;i<candidates.size();i++){
            path.push_back(candidates[i]);
            sum+=candidates[i];
            backtracking(candidates,target,i);
            sum-=candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates,target,0);
        return res;
    }
};