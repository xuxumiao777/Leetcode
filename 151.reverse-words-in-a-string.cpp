class Solution {
public:
    string reverseWords(string s) {
        stack<string> temp;
        int left=0;
        while(s[left]==' '){
            left++;
        }
        cout<<left<<endl;
        for(int i=left;i<=s.size();i++){
            if(s[i]==' '||s[i]=='\0'){
                temp.push(s.substr(left,i-left));
                while(s[i]==' '){
                    i++;
                }
                left=i;
            }

        }
        string res;
        while(!temp.empty()){
            res.append(temp.top()+' ');
            temp.pop();
        }
        res.erase(res.end()-1,res.end());
        return res;
    }
};