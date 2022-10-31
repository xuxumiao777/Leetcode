class Solution {
public:
    string intToRoman(int num) {
        //special
        // if(num==4){
        //     return "IV";
        // }
        // if(num==9){
        //     return "IX";
        // }
        // if(num==40){
        //     return "XL";
        // }
        // if(num==90){
        //     return "XC";
        // }
        // if(num==400){
        //     return "CD";
        // }
        // if(num==900){
        //     return "CM";
        // }
        string res;
        while(num-1000>=0){
            num=num-1000;
            res.append("M");
        }
        if(num>=900&&num<=999){
            num-=900;
            res.append("CM");
        }
        while(num-500>=0){
            num-=500;
            res.append("D");
        }
        if(num>=400&&num<=499){
            num-=400;
            res.append("CD");
        }
        if(num>=900&&num<=999){
            num-=900;
            res.append("CM");
        }
        while(num-100>=0){
            num-=100;
            res.append("C");
        }
        if(num>=90&&num<=99){
            num-=90;
            res.append("XC");
        }                
        while(num-50>=0){
            num=num-50;
            res.append("L");
        }
        if(num>=40&&num<=49){
            num-=40;
            res.append("XL");
        }
        while(num-10>=0){
            num-=10;
            res.append("X");
        }
        if(num==9){
            num-=9;
            res.append("IX");
        }
        while(num-5>=0){
            num-=5;
            res.append("V");
        }
        if(num==4){
            num-=4;
            res.append("IV");
        }
        while(num-1>=0){
            num--;
            res.append("I");
        }
        return res;
    }
};