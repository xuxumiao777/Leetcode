class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_num=0;
        int max_size=nums.size();
        int index=0;
        int temp=0;
        while(index<max_size){
            if(nums[index]==0){
                index++;
            }
            temp=index;
            while(index<max_size&&nums[index]==1){
                index++;

            }
            max_num=(index-temp)>max_num?(index-temp):max_num;

        }
        return max_num;


    }
};
