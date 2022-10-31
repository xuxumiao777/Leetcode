class Solution {
public:
    int largestPalindrome(int n) {
        if(n==1){
            return 9;
        }
        int upper=pow(10,n)-1;
        
        for(int left=upper;;left--){
            long long p=left;
            int x=left;
            int factor=pow(10,n-1);
            while(x){
                p=p*10+x%10;
                x=x/10;
            }
            //cout<<p<<endl;
            for(long long z=upper;z*z>=p;z--){
                if(p%z==0){
                    return p%1337;
                }
            }
        }
        return 0;
    }
};