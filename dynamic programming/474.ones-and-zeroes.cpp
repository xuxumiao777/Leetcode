class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> state(m+1,vector<int>(n+1,0));
        for(auto str:strs){
            int num_zero=0,num_one=0;
            for(auto ch:str){
                if(ch=='0'){
                    num_zero++;
                }
                else{
                    num_one++;
                }
            }
            for(int i=m;i>=num_zero;i--){
                for(int j=n;j>=num_one;j--){
                    state[i][j]=max(state[i][j],state[i-num_zero][j-num_one]+1);
                }
            }
            
        }
        return state[m][n];
    }
};