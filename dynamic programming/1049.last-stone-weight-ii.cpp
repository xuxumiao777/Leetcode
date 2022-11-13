class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum_weight=0;
        for(auto &stone:stones){
            sum_weight+=stone;
        }
        int weight=sum_weight/2;
        vector<int> state(weight+1,0);
        //init
        for(int i=stones[0];i<=weight;i++){
            state[i]=stones[0];
        }
        for(int i=1;i<stones.size();i++){
            for(int j=weight;j>=0;j--){
                if(stones[i]<=j)
                    state[j]=max(state[j],state[j-stones[i]]+stones[i]);
                    //cout<<state[j]<<";";
            }
            //cout<<";"<<endl;
        }
        return sum_weight-2*state[weight];
    }
};