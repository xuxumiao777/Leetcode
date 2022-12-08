//和1143最长公共子序列一致
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int len_num1=nums1.size();
        int len_num2=nums2.size();
        vector<vector<int>> state(len_num1+1,vector<int>(len_num2+1,0));
        int res=0;
        for(int i=1;i<=len_num1;i++){
            for(int j=1;j<=len_num2;j++){
                if(nums1[i-1]==nums2[j-1]){
                    state[i][j]=state[i-1][j-1]+1;
                }
                else{
                    state[i][j]=max(state[i-1][j],state[i][j-1]);
                }
                res=max(res,state[i][j]);
            }
        }
        return res;
    }
};