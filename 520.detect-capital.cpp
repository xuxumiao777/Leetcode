class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size()>=2&&islower(word[0])&&isupper(word[1])){
            return false;
        }
        for(int i=1;i<word.size()-1;i++){
            if(islower(word[i])!=islower(word[i+1])){
                return false;
            }
        }
        return true;
    }
};
