class Solution {
public:
    int maximumScore(int a, int b, int c) {
        vector<int> temp(3);
        temp[0]=a;
        temp[1]=b;
        temp[2]=c;
        sort(temp.begin(),temp.end());
        int res=0;
        if(temp[2]>=(temp[0]+temp[1])){
            return temp[0]+temp[1];
        }
        else{
            while(temp[2]<(temp[1]+temp[0])){
                temp[1]--;
                temp[0]--;
                res++;
            }
            res+=temp[0];
            res+=temp[1];
        }
        return res;
    }
};