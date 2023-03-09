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
//09-03-2023

class Solution {
public:
    stack<char> bracket;
    bool isValid(string s) {
        for(auto ch:s){
            if(ch==')'){
                if(!bracket.empty()&&bracket.top()=='('){
                    bracket.pop();
                }
                else{
                    return false;
                }
            }
            else if(!bracket.empty()&&ch==']'){
                if(bracket.top()=='['){
                    bracket.pop();
                }
                else{
                    return false;
                }
            }
            else if(!bracket.empty()&&ch=='}'){
                if(bracket.top()=='{'){
                    bracket.pop();
                }
                else{
                    return false;
                }
            }
            else{
                bracket.push(ch);
            }
        }
        if(bracket.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};