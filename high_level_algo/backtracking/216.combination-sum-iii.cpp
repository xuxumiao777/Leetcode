class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    int sum=0;
    void backtracking(int n,int k,int startindex){
        if(sum>n){
            return;
        }
        if(k==path.size()){
            //cout<<"here"<<endl;
            if(sum==n){
                res.push_back(path);
            }
            return;
        }
        for(int i=startindex;i<=9;i++){
            sum += i;
            path.push_back(i);
            //cout<<sum<<endl;
            backtracking(n,k,i+1);
            sum -= i;
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        //res.clear();
        backtracking(n,k,1);
        return res;
    }
};