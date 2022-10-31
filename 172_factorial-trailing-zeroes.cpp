class Solution {
public:
    int trailingZeroes(int n) {
        if(n==0){
            return 0;
        }
        int num_zero=0;
        while(n!=0){
            int temp=n;
            while(temp%5==0){
                num_zero++;
                temp=temp/5;
            }
            n--;
        }
        return num_zero;

    }
};