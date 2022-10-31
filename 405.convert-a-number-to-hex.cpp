class Solution {
public:
    string toHex(int num) {
        string res;
        if(num==0){
            return "0";
        }
        long n=num;

        if(n<0){
            n+=pow(2,32);
        }
        cout<<n<<endl;
        while(n){
            long temp=n%16;
            cout<<temp<<endl;
            if(temp<10){
                res.push_back((char)(temp+'0'));
            }
            else{
                res.push_back((char)('a'+temp-10));
            }
            n=n/16;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};