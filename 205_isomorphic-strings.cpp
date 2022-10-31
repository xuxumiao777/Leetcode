class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> hashmap;
        unordered_set<char> hashset;
        for(int i=0;i<s.size();i++){
            if(hashmap.count(s[i])>0){
                if(hashmap[s[i]]!=t[i]){
                    return false;
                }
                else{
                    continue;
                }
            }
            else {
                hashmap[s[i]]=t[i];
                if(hashset.count(t[i])<=0){
                    hashset.insert(t[i]);

                }
                else{
                    return false;
                }

            }
            
        }
        return true;

    }
};