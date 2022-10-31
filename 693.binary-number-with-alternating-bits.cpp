class Solution {
public:
    bool hasAlternatingBits(int n) {
        int temp=0;
        int i;
        for(i=31;i>=0;i--){
            if(n>>i&1==1){
                break;
            }
        }

        for(int j=i;j>=0;j--){

            int res=n>>j&1;

            if((res+temp)!=1){
                return false;
            }
            if(temp==0){
                temp=1;
                continue;
            }
            if(temp==1){
                temp=0;
                continue;
            }
        }

        return true;
    }
};