class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> temp;
        int num=0;
        char flag=s[0];
        s+='-';
        for(auto character:s){
            if(character==flag){
                num++;
            }
            if(character=='-'){
                temp.push_back(num);
            }
            else if(character!=flag&&character!='-'){
                temp.push_back(num);
                flag=character;
                num=1;
            }
        }
        int res=0;
        for(int i=0;i<temp.size()-1;i++){
            res+=min(temp[i],temp[i+1]);
            
        }
        return res;
    }
};