class Solution {
public:
    int maximumSwap(int num) {
        vector<int> temp;
        while(num){
            temp.push_back(num%10);
            num/=10;
        }
        int size=temp.size();
        for(int i=size-1;i>=0;i--){
            int to_swap=temp[i];
            int max_to_swap=to_swap;
            int j_now=0;
            for(int j=i-1;j>=0;j--){
                if(temp[j]>=max_to_swap){
                    max_to_swap=temp[j];
                    j_now=j;
                }
            }
            if(max_to_swap>to_swap){
                temp[j_now]=to_swap;
                temp[i]=max_to_swap;
                break;
            }
        }
        int ans=0;
        for(int i=size-1;i>=0;i--){
            ans=ans*10+temp[i];
        }
        return ans;
    }
};