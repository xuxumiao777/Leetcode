class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> hashmap;
        vector<vector<string>> result;
        for(auto str:strs){
            auto key=str;
            sort(key.begin(),key.end());
            hashmap[key].push_back(str);
        }
        for(auto it=hashmap.begin();it!=hashmap.end();it++){
            result.push_back(it->second);
        }
        return result;

    }
};