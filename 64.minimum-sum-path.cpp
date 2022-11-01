class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int width=grid.size();
        int length=grid[0].size();
        int state[width][length];
        state[0][0]=grid[0][0];
        for(int i=0;i<width;i++){
            for(int j=0;j<length;j++){
                if(i==0&&j==0){
                    state[i][j]=grid[i][j];
                }
                else if(i==0&&j>0){
                    state[i][j]=grid[i][j]+state[i][j-1];
                }
                else if(j==0&&i>0){
                    state[i][j]=grid[i][j]+state[i-1][j];
                }
                else{
                    state[i][j]=min(state[i-1][j],state[i][j-1])+grid[i][j];
                }
            }
        }
        return state[width-1][length-1];
        
    }
};
