class Solution {
public:
    string removeOuterParentheses(string s) {
        int len=s.length();
        string s_new=s;
        string s_out;
        for(int i=1,left=1,right=0;i<len;i++){
            if(s_new[i]=='('){
                left++;
                
                s_out.push_back('(');
            }
            else{
                right++;
                
                s_out.push_back(')');
            }
            if(left==right){
                s_out.pop_back();
                i++;
                left++;
            }
        }
        //s_out.push_back(')');
    return s_out;
    }
};