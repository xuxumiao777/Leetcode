class Solution {
public:
    void print_state(vector<vector<bool>> &state){
        for(int i=0;i<state.size();i++){
            for(int j=0;j<state[0].size();j++){
                cout<<state[i][j];
            }
            cout<<";"<<endl;
        }
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int size=nums.size();
        for(int i=0;i<size;i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        int weight=sum/2;
        vector<vector<bool>> state(size,vector<bool>(weight+1,false));
        //initialization
        if(nums[0]<=weight){
            state[0][nums[0]]=true;
        }
        for(int j=1;j<=weight;j++){
            for(int i=1;i<size;i++){
                if(state[i-1][j]){
                    state[i][j]=true;
                }
                if(nums[i]<=j){
                    state[i][nums[i]]=true;
                    if(state[i-1][j-nums[i]]){
                        state[i][j]=true;
                    }
                }

            }
        }
        //return 1;
        //print_state(state);
        return state[size-1][weight];
    }
};