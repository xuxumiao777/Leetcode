class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int size_s1=nums1.size();
        int size_s2=nums2.size();
        vector<vector<int>> state(size_s1+1,vector<int>(size_s2+1,0));
        int res=0;
        for(int i=1;i<=size_s1;i++){
            for(int j=1;j<=size_s2;j++){
                if(nums1[i-1]==nums2[j-1]){
                    state[i][j]=state[i-1][j-1]+1;
                }
                if(state[i][j]>res){
                    res=state[i][j];
                }
            }
        }
        return res;
    }
};