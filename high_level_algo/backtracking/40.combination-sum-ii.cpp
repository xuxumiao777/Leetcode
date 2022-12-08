class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    int sum=0;
    void backtracking(vector<int> &candidates,int target,int index,vector<bool> &used){
        if(sum>target){
            return;
        }
        if(sum==target){
            res.push_back(path);
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(i>0&&candidates[i]==candidates[i-1]&&used[i-1]==false){
                continue;
            }
            path.push_back(candidates[i]);
            sum+=candidates[i];
            used[i]=true;
            backtracking(candidates,target,i+1,used);
            used[i]=false;
            sum-=candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<bool> used(candidates.size(),false);
        backtracking(candidates,target,0,used);
        return res;
    }
};