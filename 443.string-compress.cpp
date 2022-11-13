class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> s;
        for(int i=0;i<chars.size();i++){
            int num=1;
            s.push_back(chars[i]);
            while(i<chars.size()-1&&chars[i+1]==chars[i]){
                num++;
                i++;
            }
            if(num==1){
                continue;
            }
            cout<<num<<endl;
            cout<<num%10<<endl;
            stack<char> temp;
            while(num){
                temp.push(to_string(num%10)[0]);
                num=num/10;
            }
            while(!temp.empty()){
                s.push_back(temp.top());
                temp.pop();
            }
        }
        chars=s;
        return chars.size();
    }
};