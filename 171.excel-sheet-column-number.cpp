class Solution {
public:
    int titleToNumber(string columnTitle) {
        int size=columnTitle.size();
        int res=0;
        int temp=size;
        for(int i=0;i<size;i++){
            temp--;
            res+=(columnTitle[i]-'A'+1)*pow(26,temp);
        }
        return res;
    }
};