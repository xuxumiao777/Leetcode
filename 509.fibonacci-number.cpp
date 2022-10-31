class Solution {
public:
    int F[31];
    int Fibo(int n){
        
        if(F[n]!=-1){
            return F[n];
        }
        return F[n]=Fibo(n-1)+Fibo(n-2);
    }
    

    int fib(int n) {
        for(int i=0;i<=30;i++){
            F[i]=-1;
        }
        F[0]=0;F[1]=1;
        int res=Fibo(n);
        return res;
    }
};