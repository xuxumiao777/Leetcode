class Solution {
public:
    bool isPalindrome(string s) {
        string s_new;
        for(int i=0;i<s.size();i++){
            if(isupper(s[i])){
                s_new.push_back(tolower(s[i]));
            }
            else if(islower(s[i])||isdigit(s[i])){
                s_new.push_back(s[i]);
            }
        }
        if(s_new.size()<=1){
            return true;
        }
        
        for(int i=0;i<s_new.size()/2;i++){
            if(s_new[i]!=s_new[s_new.size()-i-1]){
                return false;
            }
        }
        return true;
    }
};
