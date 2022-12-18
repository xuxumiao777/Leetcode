class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        vector<int> temp;
        while(n){
            temp.push_back(n%10);
            n=n/10;
        }
        if(temp.size()==1){
            return n;
        }
        int res=0;
        for(int i=1;i<temp.size();i++){
            if(temp[i]>temp[i-1]){
                for(int j=0;j<i;j++){
                    temp[j]=9;
                }
                temp[i]-=1;
            }
        }
        for(int i=0;i<temp.size();i++){
            res+=temp[i]*pow(10,i);
        }
        return res;
    }
};