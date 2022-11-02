class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int num=1;
        if(n==1){
            matrix[0][0]=1;
            return matrix;
        }
        if(n%2==0){
            for(int i=0;i<n/2;i++){
                for(int iter=i;iter<n-i;iter++){
                    matrix[i][iter]=num++;
                }
                for(int iter=i+1;iter<n-i;iter++){
                    matrix[iter][n-i-1]=num++;
                }
                for(int iter=n-i-2;iter>=i;iter--){
                    matrix[n-i-1][iter]=num++;
                }
                for(int iter=n-i-2;iter>i;iter--){
                    matrix[iter][i]=num++;
                }
            }
        }
        else{
            for(int i=0;i<n/2;i++){
                for(int iter=i;iter<n-i;iter++){
                    matrix[i][iter]=num++;
                }
                for(int iter=i+1;iter<n-i;iter++){
                    matrix[iter][n-i-1]=num++;
                }
                for(int iter=n-i-2;iter>=i;iter--){
                    matrix[n-i-1][iter]=num++;
                }
                for(int iter=n-i-2;iter>i;iter--){
                    matrix[iter][i]=num++;
                }
            }
            
            matrix[n/2][n/2]=num++;

        }
        return matrix;
    }
};