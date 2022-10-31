class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> hashmap;
        for(auto num:s){
            hashmap[num]++;
        }
        unordered_map<char,int> hashmap2;
        for(auto num:t){
            hashmap2[num]++;
        }
        for(auto num:t){
            if(hashmap2[num]!=hashmap[num]){
                return false;
            }
        }
        for(auto num:s){
            if(hashmap2[num]!=hashmap[num]){
                return false;
            }
        }
        return true;
    }
};