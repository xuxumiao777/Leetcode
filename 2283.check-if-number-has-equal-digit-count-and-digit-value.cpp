class Solution {
public:
    bool digitCount(string num) {
        unordered_map<int,int> hashmap;
        for(auto ch:num){
            hashmap[ch-'0']++;
        }
        for(int i=0;i<num.size();i++){
            if(hashmap[i]!=num[i]-'0'){
                return false;
            }
        }
        return true;
    }
};