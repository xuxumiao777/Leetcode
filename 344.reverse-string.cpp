class Solution {
public:
    void reverseString(vector<char>& s) {
        int length=s.size();
        char temp;
        for(int i=0;i<length/2;i++){
            temp=s[i];
            s[i]=s[length-1-i];
            s[length-1-i]=temp;
        }
    }
};