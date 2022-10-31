class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=0;
        digits[digits.size()-1]++;
        if(digits[digits.size()-1]/10){
            carry=1;
            digits[digits.size()-1]=digits[digits.size()-1]%10;
        }
        for(int i=digits.size()-2;i>=0;i--){
            
                digits[i]=digits[i]+carry;
                if(digits[i]/10){
                    carry=1;
                    digits[i]=(digits[i]%10);
                }
                else{
                    carry=0;
                    break;
                }
            
        }
        cout<<carry<<endl;
        vector<int> temp(digits.size()+1);
        if(carry){
            
            for(int i=temp.size()-1;i>=1;i--){
                temp[i]=digits[i-1];
            }
            temp[0]=1;
            digits=temp;
        }
        
        return digits;
    }
};