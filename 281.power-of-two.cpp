class Solution {
public:
    bool PowerOfTwo(long long n){
        if(n<=0){
            return false;
        }
        if(n==1){
            return true;
        }
        if(n%2==0){
            return isPowerOfTwo(n/2);
        }
        return false;        
    }
    bool isPowerOfTwo(int n) {
        
        return PowerOfTwo(n);
    }
};