class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> temp(52);
        for(auto ch:s){
            if(islower(ch)){
                temp[ch-'a']++;
            }
            else{
                temp[ch-'A'+26]++;
            }            
        }
        int res=0;
        int odd=0;
        for(int i=0;i<52;i++){
            if(temp[i]%2==0){
                res+=temp[i];
            }
            else{
                odd=1;
                res+=(temp[i]-1);
            }
        }
        return res+odd;
    }
};