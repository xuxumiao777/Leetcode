class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int min_bi=40000+1;
        int min_ai=40000+1;
        int row=ops.size();
        if(ops.empty()){
            return m*n;
        }
        for(int i=0;i<row;i++){
            if(ops[i][0]<=m&&ops[i][1]<=n)
                min_ai=ops[i][0]<min_ai?ops[i][0]:min_ai;
                min_bi=ops[i][1]<min_bi?ops[i][1]:min_bi;
        }
        if(min_ai==40001&&min_bi==40001)
            return m*n;
        return min_bi*min_ai;
        
    }
};
