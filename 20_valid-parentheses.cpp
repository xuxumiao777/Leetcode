class Solution {
public:
    bool isValid(string s) {
        int len=s.length();
        stack<char> stk;
        for(int i=0;i<len;i++){
            if(s[i]=='('||s[i]=='['||s[i]=='{'){
                stk.push(s[i]);
            }
            else if(stk.empty()){
                return false;
            }
            else if(s[i]==')'){
                
                if(stk.top()=='('){
                    stk.pop();
                }
                else{
                    return false;
                }
            }
            else if(s[i]==']'){
                if(stk.top()=='['){
                    stk.pop();
                }
                else{
                    return false;
                }
            }
            else if(s[i]=='}'){
                if(stk.top()=='{'){
                    stk.pop();
                }
                else{
                    return false;
                }
            }                        
        }
        return stk.empty();



    }
};
