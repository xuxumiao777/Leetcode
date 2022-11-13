class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> hashmap;
        for(auto num:s){
            hashmap[num]++;
        }
        for(auto num:t){
            if(hashmap[num]!=0){
                hashmap[num]--;
            }
            else{
                return num;
            }
        }
        return ' ';
    }
};