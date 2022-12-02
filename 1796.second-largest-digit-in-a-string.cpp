class Solution {
public:
    int secondHighest(string s) {
        vector<int> temp;
        for(auto ch:s){
            if(isdigit(ch)){
                temp.push_back(ch-'0');
            }
        }
        if(temp.size()==0){
            return -1;
        }
        sort(temp.begin(),temp.end(),greater<>());
        int res=temp[0];
        for(auto val:temp){
            if(val!=res){
                res=val;
                return res;
            }
        }
        return -1;
    }
};
