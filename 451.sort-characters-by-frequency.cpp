class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> hashmap;
        for(auto num:s){
            hashmap[num]++;
        }
        vector<pair<char,int>> vec;
        for(auto t:hashmap){
            vec.push_back(t);
        }
        sort(vec.begin(),vec.end(),[](const pair<char,int> &num1,const pair<char,int> &num2){return num1.second>num2.second;});
        string res;
        for(auto t:vec){
            while(t.second--){
                res.push_back(t.first);
            }
            
        }
        return res;
    }
};