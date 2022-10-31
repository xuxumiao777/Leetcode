class Solution {
public:
    int magicalString(int n) {
        if(n<=3){
            return 1;
        }
        string str="122";
        int i=2;//i points to the end of unspanned string
        while(str.size()<n){
            char lastch=str.back();
            if(lastch=='1'){
                if(str[i]=='1'){
                    str.append("2");
                }
                else{
                    str.append("22");
                }
            }
            else if(lastch=='2'){
                if(str[i]=='1'){
                    str.append("1");
                }
                else{
                    str.append("11");
                }
            }
            i++;
        }
        
        
        return count(str.begin(),str.begin()+n,'1');
    }
};