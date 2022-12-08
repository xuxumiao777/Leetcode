class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(),dictionary.end(),[](string &a,string &b){
            if(a.size()!=b.size()){
                return a.size()>b.size();
            }
            else{
                for(int i=0;i<a.size();i++){
                    if(a[i]!=b[i])
                        return a[i]<b[i];
                }
            }
            return a.size()>b.size();
        });

        for(int i=0;i<dictionary.size();i++){
            int p1=0,p2=0;
            while(p1<s.size()&&p2<dictionary[i].size()){
                if(s[p1]==dictionary[i][p2]){
                    p1++;
                    p2++;
                }
                else{
                    p1++;
                }
            }
            //cout<<p1<<endl;
            //cout<<p2<<endl;
            if(p2==dictionary[i].size()){
                return dictionary[i];
            }
            
        }
        return "";
    }
};