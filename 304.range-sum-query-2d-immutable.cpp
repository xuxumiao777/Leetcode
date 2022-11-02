class NumMatrix {
public:
    vector<vector<int>> presum;
    int sum;
    NumMatrix(vector<vector<int>>& matrix) {
        //vector<vector<int>> presum;
        int m=matrix.size();
        int n=matrix[0].size();
        presum.resize(m+1,vector<int>(n+1));
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                presum[i][j]=matrix[i-1][j-1]+presum[i-1][j]+presum[i][j-1]-presum[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        sum=presum[row2+1][col2+1]-presum[row1][col2+1]-presum[row2+1][col1]+presum[row1][col1];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */