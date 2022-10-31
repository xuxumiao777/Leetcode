class Solution {
public:
    string countAndSay(int n) {
        string res="1";
        if(n==1){
            return "1";
        }
        //cout<<n;
        for(int j=2;j<=n;j++){
            string temp;
            for(int i=0;i<res.size();i++){
                int num=1;
                int n=res[i]-'0';
                
                while(res[i+1]==res[i]){
                    num++;
                    i++;
                }
                temp.append(to_string(num));
                temp.append(to_string(n));
            }
            res=temp;
        }
        return res;
    }
};