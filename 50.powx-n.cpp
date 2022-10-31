class Solution {
public:
    double pow(double x,long long n){
        if(x==0&&n==0){
            return 1.0;
        }
        if(n==0){
            return 1.0;
        }
        else if(n%2==0){
            double y=myPow(x,n/2);
            return y*y;
        }
        else{
            return x*myPow(x,n-1);
        }        
    }
    double myPow(double x, int n) {
        double N=n;
        return n>=0?pow(x,N):1/pow(x,-N);
    }
};