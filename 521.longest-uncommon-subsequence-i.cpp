class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a!=b){
            return max(a.size(),b.size());
        }
        else{
            return -1;
        }
    }
};