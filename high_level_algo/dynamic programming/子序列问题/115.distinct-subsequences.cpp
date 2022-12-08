class Solution {
public:
    int numDistinct(string s, string t) {
        int s_len=s.size();
        int t_len=t.size();
        vector<vector<uint64_t>> state(s_len+1,vector<uint64_t>(t_len+1,0));
        for(int i=0;i<=s_len;i++){
            state[i][0]=1;
        }
        for(int i=1;i<=s_len;i++){
            for(int j=1;j<=t_len;j++){
                if(s[i-1]==t[j-1]){
                    state[i][j]=state[i-1][j]+state[i-1][j-1];
                }
                else{
                    state[i][j]=state[i-1][j];
                }
            }
        }
        return (int)state[s_len][t_len];
    }
};