class Solution {
public:
    int myAtoi(string s) {
        int begin,end=0;
        long long int res=0;
        for(int i=0;i<=s.size();i++){
            if(isdigit(s[i])){
                begin=i;
                while(isdigit(s[i])){
                    i++;
                    end=i;
                }
                break;
                
            }
            else if(s[i]!=' '&&s[i]!='-'&&s[i]!='+'){
                cout<<"here"<<endl;
                return 0;
            }
            

            
            

        }
        int sgn=1;
        cout<<begin<<endl;
        cout<<end<<endl;
        for(int i=0;i<begin-1;i++){

            if(s[i]!=' '&&s[i]!='0'){
                return 0;
            }
        }
        if(begin>=1&&s[begin-1]=='-'){
            sgn=-1;
        }
        for(int i=begin;i<end-1;i++){
            if(s[i]=='0'){
                begin++;
            }
            else{
                break;
            }
        }
        
        cout<<begin<<endl;
        int res_final=0;

        string str_new=s.substr(begin,end-begin);
        if(end-begin>=11){
            if(sgn==1){
                return pow(2,31)-1;
            }
            else{
                return -pow(2,31);
            }
        }
        res=stoll(str_new);
        cout<<str_new<<endl;

        //cout<<res*sgn<<endl;
        if(res*sgn>pow(2,31)-1){
            return pow(2,31)-1;

        }
        if(res*sgn<-pow(2,31)){
            return -pow(2,31);
        }
        else{
            
            res_final=res*sgn;
        }
        return res_final;
    }
};
//DFA
class Automation{
    unordered_map<string,vector<string>> table={
        {"start",{"start","signed","in_number","end"}},
        {"signed",{"end","end","in_number","end"}},
        {"in_number",{"end","end","in_number","end"}},
        {"end",{"end","end","end","end"}}
    };
    
    public:
    string state="start";
    long long ans=0;
    int sgn=1;

    int get_col(char c){
        if(c==' '){
            return 0;
        }
        if(c=='+'||c=='-'){
            return 1;
        }
        if(isdigit(c)){
            return 2;
        }
        else{
            return 3;
        }
        return 3;

    }
    void calculate(char c){
        state=table[state][get_col(c)];
        if(state=="signed"){
            if(c=='-'){
                sgn=-1;
            }
        }
        if(state=="in_number"){
            if(sgn==1){
                ans=min(ans*10+c-'0',(long long)INT_MAX);
            }
            else{
                ans=min(ans*10+c-'0',-(long long)INT_MIN);
            }
        }
    }
};
class Solution {
public:
    int myAtoi(string s) {
        Automation automation;
        for(char c:s){
            automation.calculate(c);
            if(automation.state=="end"){
                break;
            }

        }
        return automation.sgn*automation.ans;
    }
};