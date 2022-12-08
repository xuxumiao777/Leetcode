class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordset(wordDict.begin(),wordDict.end());
        vector<int> state(s.size()+1,0);
        state[0]=1;
        for(int i=1;i<=s.size();i++){
            for(int j=0;j<i;j++){
                string word=s.substr(j,i-j);
                if(wordset.find(word)!=wordset.end()&&state[j]==1){
                    state[i]=1;
                }
            }
        }
        return state[s.size()];
    }
};