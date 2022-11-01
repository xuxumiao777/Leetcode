class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int width=obstacleGrid.size();
        int length=obstacleGrid[0].size();
        int state[width][length];
        state[0][0]=obstacleGrid[0][0]==1?0:1;
        //cout<<state[0][0]<<endl;
        for(int i=0;i<width;i++){
            for(int j=0;j<length;j++){
                if(obstacleGrid[i][j]==1){
                    state[i][j]=0;
                    continue;
                }
                if(j>0&&i>0){
                    state[i][j]=state[i-1][j]+state[i][j-1];
                }
                else if(j>0){
                    state[i][j]=state[i][j-1];
                }
                else if(i>0){
                    state[i][j]=state[i-1][j];
                }
            }
        }
        //cout<<state[0][0]<<endl;
        return state[width-1][length-1];
    }
};
