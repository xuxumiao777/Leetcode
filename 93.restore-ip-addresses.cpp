class Solution {
public:
    vector<string> path;
    vector<vector<string>> res;
    bool isValid(string &s,int startindex,int endindex){
        if((endindex-startindex)>=3){
            return false;
        }
        if((s[startindex]=='0')&&(startindex!=endindex)){
            return false;
        }
        int temp=0,cur=0;
        for(int i=startindex;i<=endindex;i++){
            cur=s[i]-'0';
            temp=temp*10+cur;
        }
        if(temp>255){
            return false;
        }
        return true;
    }
    void backtracking(string &s,int startindex){
        if(startindex>s.size()||path.size()>4){
            return;
        }
        if((startindex==s.size())&&(path.size()==4)){
            //cout<<"here"<<endl;
            res.push_back(path);
        }
        for(int i=startindex;i<s.size();i++){
            if(isValid(s,startindex,i)){
                path.push_back(s.substr(startindex,i-startindex+1)+'.');
                backtracking(s,i+1);
                path.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        backtracking(s,0);
        vector<string> result;
        //cout<<res.size()<<endl;
        for(auto temp:res){
            string str_temp;
            for(auto str:temp){
                str_temp+=str;
            }
            str_temp.erase(str_temp.size()-1,1);
            result.push_back(str_temp);
            
        }
        return result;
    }
};
