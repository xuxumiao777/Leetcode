class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
    static const int MAXN = 1e5 + 5;
    int cnt[26][MAXN]; 
    for(int i=0;i<s.size();i++){
        for(int j=0;j<26;j++){
            cnt[j][i+1]=cnt[j][i];
        }
        cnt[s[i]-'a'][i+1]++;
    }
    vector<bool> result;
    int even_num=0;
    for(int i=0;i<queries.size();i++){        
        even_num=0;
        int left=queries[i][0];
        int right=queries[i][1];
        int allowed_even=(right-left)%2==0?2*queries[i][2]+1:2*queries[i][2];
        for(int j=0;j<26;j++){
            even_num+=(cnt[j][right+1]-cnt[j][left])%2;

        }
        if(even_num<=allowed_even){
            result.push_back(true);
        }
        else{
            result.push_back(false);
        }
    }
    return result;
    }
};