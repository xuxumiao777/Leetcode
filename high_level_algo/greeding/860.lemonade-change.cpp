class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> earns={0,0,0};
        int pay_back=0;
        for(auto bill:bills){
            if(bill==5){
                earns[0]++;
            }
            else if(bill==10){
                if(earns[0]<=0){
                    return false;
                }
                else{
                    earns[0]--;
                    earns[1]++;
                }
            }
            else{
                if(earns[1]>0&&earns[0]>0){
                    earns[1]--;
                    earns[0]--;
                }
                else if(earns[1]==0&&earns[0]>=3){
                    earns[0]-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};