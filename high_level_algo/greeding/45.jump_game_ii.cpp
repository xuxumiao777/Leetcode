class Solution {
public:
    int jump(vector<int>& nums) {
        int times=0;
        int cover=0;
        int temp=0;
        int origin=0;
        while(cover<nums.size()-1){
            times++;
            //cout<<cover<<endl;
            temp=cover;
            for(int i=origin;i<=cover;i++){
                origin=cover;
                temp=max(temp,i+nums[i]);
                if(cover>=nums.size()-1){
                    return times;
                }   
            }
            cover=temp;            
        }
        return times;
    }
};