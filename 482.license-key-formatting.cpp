class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        vector<char> temp;
        for(auto ch:s){
            if(islower(ch)){
                temp.push_back(toupper(ch));
            }
            else if(ch=='-'){
                continue;
            }
            else{
                temp.push_back(ch);
            }
        }
        string res;
        if(temp.size()==0){
            return "";
        }
        for(int i=0;i<temp.size()%k;i++){
            res.push_back(temp[i]);
        }
        if(temp.size()%k!=0){
            res.push_back('-');
        }
        
        int start=temp.size()%k;
        for(int i=0;i<temp.size()/k;i++){
            for(int j=0;j<k;j++){
                res.push_back(temp[start]);
                start++;
            }
            res.push_back('-');
        }
        res.erase(res.size()-1,1);
        return res;
    }
};