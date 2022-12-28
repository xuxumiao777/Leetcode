class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n=row.size();
        int loc[n];
        for(int i=0;i<n;i++) {
            loc[row[i]]=i;
        }
        int ret=0;
        for(int i=0;i<n-1;i+=2) {
            int a=row[i],b=a^1;
            if(row[i+1]!=b) {
                loc[row[i+1]]=loc[b];
                swap(row[i+1],row[loc[b]]);
                loc[b]=i+1;
                ret++;
            }
        }
        return ret;
    }
};