class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int size=matrix.size();
        for(int row=size-2;row>=0;row--){
            for(int col=0;col<size;col++){
                if(col==0){
                    matrix[row][col]+=min(matrix[row+1][col],matrix[row+1][col+1]);
                }
                else if(col==size-1){
                    matrix[row][col]+=min(matrix[row+1][col],matrix[row+1][col-1]);
                }
                else{
                    matrix[row][col]+=min(matrix[row+1][col+1],min(matrix[row+1][col],matrix[row+1][col-1]));
                }
            }
        }
        int res=matrix[0][0];
        for(int iter=1;iter<size;iter++){
            if(matrix[0][iter]<res){
                res=matrix[0][iter];
            }
        }
        return res;
    }
};
