class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> res(r,vector<int>(c));
        if(m*n!=r*c){
            return mat;
        }
        
        else{
            queue<int> q;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    q.push(mat[i][j]);
                }
            }
            
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    res[i][j]=q.front();
                    q.pop();
                }
            }            
        }
        return res;
    }
};