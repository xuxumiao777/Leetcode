class Solution {
public:
    int div(long a,long b){
        long count=1;
        long div_b=b;
        if(a<b){
            return 0;
        }
        if(a==b){
            return 1;
        }
        while(a>(div_b+div_b)){
            count=count+count;
            div_b=div_b+div_b;
        }
        return count+div(a-div_b,b);
    }
    int divide(int dividend, int divisor) {
        long res=0;
        int symbol=1;
        long dividend_long=dividend;
        long divisor_long=divisor;
        
        // if(((dividend<=0)&&(divisor>=0))||((dividend>=0)&&(divisor<=0))){
        //     symbol=-1;
        // }
        if(((dividend<=0)^(divisor<=0))){
            symbol=-1;
        }
        if(dividend<=0){
            dividend_long=-1*dividend_long;
        }
        if(divisor<=0){
            divisor_long=-1*divisor_long;
        }
        if(symbol==1&&divisor_long==1){
            if(dividend_long>pow(2,31)-1){
                return INT_MAX;
            }
        }
        if((symbol==-1)&&(divisor_long==1)){
            if(dividend_long>=pow(2,31)){
                return INT_MIN;
                //cout<<"here"<<endl;
            }
        }
        return symbol==1?div(dividend_long,divisor_long):-div(dividend_long,divisor_long);

    }
};