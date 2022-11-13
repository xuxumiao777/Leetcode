class Num2{
    public:
    unordered_map<int,string> table={
        {1,"One "},
        {2,"Two "},
        {3,"Three "},
        {4,"Four "},
        {5,"Five "},
        {6,"Six "},
        {7,"Seven "},
        {8,"Eight "},
        {9,"Nine "},
        {10,"Ten "},
        {11,"Eleven "},
        {12,"Twelve "},
        {13,"Thirteen "},
        {14,"Fourteen "},
        {15,"Fifteen "},
        {16,"Sixteen "},
        {17,"Seventeen "},
        {18,"Eighteen "},
        {19,"Nineteen "},
        {20,"Twenty "},
        {30,"Thirty "},
        {40,"Forty "},
        {50,"Fifty "},
        {60,"Sixty "},
        {70,"Seventy "},
        {80,"Eighty "},
        {90,"Ninety "},
        {100,"Hundred "},
        {1000,"Thousand "},
        {1000000,"Million "}
    };
    string res;
    void N2W(int num){
        int temp=0;
        if(num/1000000000){
            temp=num/1000000000;
            N2W(temp);
            res.append("Billion ");
            num=num-num/1000000000*1000000000;
        }
        if(num/1000000){
            temp=num/1000000;
            N2W(temp);
            res.append("Million ");
            num=num-num/1000000*1000000;
            
        }
        if(num/1000){
            temp=num/1000;
            N2W(temp);
            num=num-temp*1000;
            res.append("Thousand ");
        }
        if(num/100){
            temp=num/100;
            num=num-temp*100;
            res.append(table[temp]);
            res.append("Hundred ");
        }
        if(num/90){
            res.append(table[90]);
            num=num-90;
        }
        if(num/80){
            res.append(table[80]);
            num=num-80;
        }
        if(num/70){
            res.append(table[70]);
            num=num-70;
        }
        if(num/60){
            res.append(table[60]);
            num=num-60;
        }
        if(num/50){
            res.append(table[50]);
            num=num-50;
        }
        if(num/40){
            res.append(table[40]);
            num=num-40;
        }
        if(num/30){
            res.append(table[30]);
            num=num-30;
        }
        if(num/20){
            res.append(table[20]);
            num=num-20;
        }
        if(num<=20&&num>0){
            res.append(table[num]);
            return;
        }                                               
    }
};
class Solution {
public:

    string numberToWords(int num) {
        if(num==0){
            return "Zero";
        }

        Num2 obj;
        obj.N2W(num);

        return obj.res.substr(0,obj.res.size()-1);
    }
};