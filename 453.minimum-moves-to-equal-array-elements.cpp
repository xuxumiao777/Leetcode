class Solution {
public:
    int minMoves(vector<int>& nums) {
    
    //cout<<min(nums[0],nums[1])<<endl;
    int minimum=nums[0];
    //cout<<min<<endl;
    for(int num:nums){
        minimum=min(minimum,num);
        //minimum=num<minimum?num:minimum;
    }
    int res=0;
    //cout<<minimum<<endl;
    for(auto num:nums){
        res+=num-minimum;
    }
    return res;
    }
};
