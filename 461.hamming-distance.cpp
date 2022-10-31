class Solution {
public:
    int hammingDistance(int x, int y) {
        int res=0;
        int s=x^y;
        for(int i=0;i<32;i++){
            if(s&1==1){
                res++;
            }
            s>>=1;
        }
        return res;
    }
};