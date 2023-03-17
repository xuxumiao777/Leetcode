class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>> state(row,vector<int>(col+1,0));
        for(int i=1;i<=col;i++){
            state[0][i]=grid[0][i-1]+state[0][i-1];

        }
        for(int i=0;i<row;i++){
            state[i][0]=INT_MAX;
        }
        for(int i=1;i<row;i++){
            for(int j=1;j<=col;j++){
                state[i][j]=grid[i][j-1]+min(state[i-1][j],state[i][j-1]);
            }
        }
        return state[row-1][col];    
    }
};