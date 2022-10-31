class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m=matrix.size();
        if(matrix.empty()){
            return res;
        }
        int n=matrix[0].size();
        cout<<m<<n<<endl;
        //return res;
        if(m==1){
            for(int i=0;i<n;i++){
                res.push_back(matrix[0][i]);
            }
            return res;
        }
        if(n==1){
            for(int i=0;i<m;i++){
                res.push_back(matrix[i][0]);
            }
            return res;
        }
        if(m<=n){
            if(m%2==0){
                for(int i=0;i<m/2;i++){
                    for(int iter=i;iter<n-i;iter++){
                        res.push_back(matrix[i][iter]);
                    }
                    for(int iter=i+1;iter<m-i;iter++){
                        res.push_back(matrix[iter][n-i-1]);
                    }
                    for(int iter=n-i-2;iter>=i;iter--){
                        res.push_back(matrix[m-i-1][iter]);
                    }
                    for(int iter=m-i-2;iter>i;iter--){
                        res.push_back(matrix[iter][i]);
                    }
                }
            }
            else{
                for(int i=0;i<m/2;i++){
                    for(int iter=i;iter<n-i;iter++){
                        res.push_back(matrix[i][iter]);
                    }
                    for(int iter=i+1;iter<m-i;iter++){
                        res.push_back(matrix[iter][n-i-1]);
                    }
                    for(int iter=n-i-2;iter>=i;iter--){
                        res.push_back(matrix[m-i-1][iter]);
                    }
                    for(int iter=m-i-2;iter>i;iter--){
                        res.push_back(matrix[iter][i]);
                    }
                }
                for(int iter=n/2-((n-m)+1)/2;iter<n/2+((n-m)+2)/2;iter++){
                    res.push_back(matrix[m/2][iter]);
                }
            }
        }
        else{
            if(n%2==0){
                for(int i=0;i<n/2;i++){
                    for(int iter=i;iter<n-i;iter++){
                        res.push_back(matrix[i][iter]);
                    }
                    for(int iter=i+1;iter<m-i;iter++){
                        res.push_back(matrix[iter][n-i-1]);
                    }
                    for(int iter=n-i-2;iter>=i;iter--){
                        res.push_back(matrix[m-i-1][iter]);
                    }
                    for(int iter=m-i-2;iter>i;iter--){
                        res.push_back(matrix[iter][i]);
                    }
                }
            }
            else{
                for(int i=0;i<n/2;i++){
                    for(int iter=i;iter<n-i;iter++){
                        res.push_back(matrix[i][iter]);
                    }
                    for(int iter=i+1;iter<m-i;iter++){
                        res.push_back(matrix[iter][n-i-1]);
                    }
                    for(int iter=n-i-2;iter>=i;iter--){
                        res.push_back(matrix[m-i-1][iter]);
                    }
                    for(int iter=m-i-2;iter>i;iter--){
                        res.push_back(matrix[iter][i]);
                    }
                }
                for(int iter=m/2-((m-n+1))/2;iter<=m/2+((m-n))/2;iter++){
                    res.push_back(matrix[iter][n/2]);
                }
            }            
        }
        return res;
    }
};