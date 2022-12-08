class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    void backtracking(int n,int k,int startindex){
        if(k==path.size()){
            res.push_back(path);
            return;
        }
        for(int i=startindex;i<n;i++){
            path.push_back(i+1);
            backtracking(n,k,i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtracking(n,k,0);
        return res;
    }
};