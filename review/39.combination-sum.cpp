class Solution {
public:
    vector<vector<int>> res;
    void backtracking(vector<int>& candidates,vector<int> cur,int target,int start){
        for(int i=start;i<candidates.size();i++){
            int candidate=candidates[i];
            if(candidate>target){
                break;                
            }
            else if(candidate==target){
                cur.push_back(candidate);
                res.push_back(cur);
                break;
            }
            else{
                //candidate<target
                cur.push_back(candidate);
                backtracking(candidates,cur,target-candidate,i);
                cur.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        sort(candidates.begin(),candidates.end());
        backtracking(candidates,cur,target,0);
        return res;
    }
};