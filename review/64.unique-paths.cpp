class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> state(m+1,vector<int>(n+1,0));
        //cout<<state.size()<<state[0].size()<<endl;
        state[1][1]=1;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(i==1&&j==1){
                    continue;
                }
                state[i][j]=state[i-1][j]+state[i][j-1];
            }
        }
        return state[m][n];
    }
};