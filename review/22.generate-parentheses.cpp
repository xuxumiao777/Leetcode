class Solution {
public:
    vector<string> res;
    void backtracking(string cur,int num_useable_left_bracket,int n,int total_left){
        if(cur.size()==2*n){
            res.push_back(cur);
        }
        else if(total_left==n){
            backtracking(cur+')',num_useable_left_bracket-1,n,total_left);
        }
        else if(num_useable_left_bracket==0){
            cur+='(';
            backtracking(cur,num_useable_left_bracket+1,n,total_left+1);
        }
        else if(num_useable_left_bracket>0){
            backtracking(cur+')',num_useable_left_bracket-1,n,total_left);
            backtracking(cur+'(',num_useable_left_bracket+1,n,total_left+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        string cur;
        backtracking(cur,0,n,0);
        return res;
    }
};