class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int carry=0;
        int size_a=a.size(),size_b=b.size();
        string result;
        if(size_a<=size_b){
            swap(a,b);
            swap(size_a,size_b);
        }
        for(int i=0;i<size_b;i++){
            result=result+to_string(((a[i]-'0')+(b[i]-'0')+carry)%2);
            carry=(a[i]-'0'+b[i]-'0'+carry)/2;

        }
        for(int i=size_b;i<size_a;i++){
            result=result+to_string(((a[i]-'0')+carry)%2);
            carry=(a[i]-'0'+carry)/2;
        }
        if(carry>0){
            result+=to_string(carry);
        }
        reverse(result.begin(),result.end());
        return result;

        

    }
};
