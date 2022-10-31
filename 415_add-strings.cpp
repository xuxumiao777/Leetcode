class Solution {
public:
    string addStrings(string num1, string num2) {
        string output("");
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int size_one=num1.size(),size_two=num2.size();
        int carry=0;
        if(size_one<=size_two){
            for(int i=0;i<size_one;i++){
                output=output+to_string((carry+(num1[i]-'0')+(num2[i]-'0'))%10);
                //cout<<(carry+num1[i]+num2[i])%10<<endl;
                carry=(carry+(num1[i]-'0')+(num2[i]-'0'))/10;

            }
            for(int i=size_one;i<size_two;i++){
                output=output+to_string(((num2[i]-'0')+carry)%10);
                carry=((num2[i]-'0')+carry)/10;
            }
            if(carry!=0){
                output=output+to_string(carry);
            }
            


        }
        else if(size_one>size_two){
            for(int i=0;i<size_two;i++){
                output=output+to_string((carry+(num1[i]-'0')+(num2[i]-'0'))%10);
                carry=(carry+(num1[i]-'0')+(num2[i]-'0'))/10;

            }
            for(int i=size_two;i<size_one;i++){
                output=output+to_string(((num1[i]-'0')+carry)%10);
                carry=((num1[i]-'0')+carry)/10;
            }
            if(carry!=0){
                output=output+to_string(carry);
            }            


        }
        reverse(output.begin(),output.end());
        return output;
    }
};
