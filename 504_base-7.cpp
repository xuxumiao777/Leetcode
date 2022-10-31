class Solution {
public:
    string convertToBase7(int num) {
        string result;
        if(num==0){
            return "0";
        }
        bool is_negative=num<0;
        if(is_negative) num=-num;
        while(num){
            int b=num%7;
            num=(num-b)/7;
            result=to_string(b)+result;
        }
        return is_negative?"-"+result:result;

    }
};