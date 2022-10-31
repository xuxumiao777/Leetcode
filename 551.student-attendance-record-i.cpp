class Solution {
public:
    bool checkRecord(string s) {
        int num_A=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='A'){
                num_A++;
            }
            if(i<s.size()-2){
                if(s[i]=='L'&&s[i+1]=='L'&&s[i+2]=='L'){
                    return false;
                }
            }
        }
        if(num_A>=2){
            return false;
        }
        return true;
    }
};