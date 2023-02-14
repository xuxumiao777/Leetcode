class Solution {
public:
    vector<string> split(string to_split, char delim){
        vector<string> ans;
        string cur;
        for(auto ch:to_split){
            if(ch==delim){
                if(cur.size()!=0){
                    ans.push_back(cur);
                    cur.clear();
                }
                else{
                    cur.clear();
                    continue;
                }

            }
            else{
                cur+=ch;
            }
        }
        if(cur!="/"){
            ans.push_back(cur);
        }
        return ans;
    }
    string simplifyPath(string path) {
        vector<string> path_split=split(path,'/');
        stack<string> stk;
        for(auto split_ele:path_split){
            cout<<split_ele<<",";
            if(split_ele=="."){
                continue;
            }
            else if(split_ele==".."){
                if(!stk.empty()){
                    stk.pop();
                }
            }
            else{
                if(split_ele.size()!=0)
                    stk.push(split_ele);
            }
        }
        stack<string> stk_temp;
        while(!stk.empty()){
            if(stk.top().size()!=0){
                cout<<stk.top()<<endl;
                stk_temp.push(stk.top());
            }
            
            stk.pop();
        }
        string res="/";
        while(!stk_temp.empty()){
            res+=stk_temp.top();
            res+='/';
            stk_temp.pop();
        }
        while(res.size()>=2&&res.back()=='/'){
            res.pop_back();
        }

        return res;
    }
};