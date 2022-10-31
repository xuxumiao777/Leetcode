class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> dict;
        for(auto num:magazine){
            dict[num]++;
        }
        for(auto num:ransomNote){
            if(dict[num]==0){
                return false;
            }
            else{
                dict[num]--;
            }
        }
        return true;
    }
};