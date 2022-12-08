class Solution {
public:
    string reverseWords(string s) {
        int left=0;
        cout<<s[s.size()]<<endl;
        for(int i=0;i<=s.size();i++){
            if(s[i]==' '||i==s.size()){
                reverse(s.begin()+left,s.begin()+i);
                i++;
                left=i;
            }
            //else if(i==s.size)
        }
        return s;
    }
};