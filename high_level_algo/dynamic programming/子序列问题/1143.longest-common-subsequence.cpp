class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len_text1=text1.size();
        int len_text2=text2.size();
        vector<vector<int>> state(len_text1+1,vector<int>(len_text2+1,0));
        int res=0;
        for(int i=1;i<=len_text1;i++){
            for(int j=1;j<=len_text2;j++){
                if(text1[i-1]==text2[j-1]){
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