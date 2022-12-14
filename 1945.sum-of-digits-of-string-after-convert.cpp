class Solution {
public:
    int getLucky(string s, int k) {
        int res=0;
        int temp=0;
        for(auto sh:s){
            temp=sh-'a'+1;
            if(temp<10){
                res+=temp;
            }
            else{
                res+=temp/10;
                res+=temp%10;
            }

        }
        if(k==1){
            return res;
        }
        //temp=res;
        cout<<res<<endl;
        //res=0;
        while(--k){
            temp=res;
            res=0;
            while(temp){
                res+=temp%10;
                temp=temp/10;
            }
            //cout<<temp<<endl;
        }
        return res;
    }
};