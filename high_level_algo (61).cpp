class Solution {
public:
    static vector<int> seperate(string num){
        vector<int> res;
        int i;
        for(i=0;i<num.size();i++){
            if(num[i]=='+'){
                break;
            }
        }
        res.push_back(stoi(num.substr(0,i)));
        res.push_back(stoi(num.substr(i+1,num.size()-2-i)));
        return res;
    }
    string complexNumberMultiply(string num1, string num2) {
        string res=to_string(seperate(num1)[0]*seperate(num2)[0]-seperate(num1)[1]*seperate(num2)[1]);
        res.append("+");
        res.append(to_string(seperate(num1)[0]*seperate(num2)[1]+seperate(num1)[1]*seperate(num2)[0])+"i");
        return res;
    }
};