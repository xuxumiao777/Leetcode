class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int,int> hash_row;
        unordered_map<int,int> hash_col;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            hash_row[i]++;
        }
        for(int i=0;i<n;i++){
            hash_col[i]++;
        }
        for(int i=0;i<m;i++){

            for(int j=0;j<n;j++){

                if(matrix[i][j]==0){
                    hash_row[i]=0;
                    hash_col[j]=0;
            
                }
            }
        }
        for(int i=0;i<m;i++){
            if(hash_row[i]==0){
                for(int j=0;j<n;j++){
                    matrix[i][j]=0;
                }
                
            }
        }        
        for(int i=0;i<n;i++){
            if(hash_col[i]==0){
                for(int j=0;j<m;j++){
                    matrix[j][i]=0;
                }
                
            }
        }                

        
    }
};
