class Solution {
public:
    void swap(vector<int>& nums,int index_1,int index_2){
        int temp=nums[index_1];
        nums[index_1]=nums[index_2];
        nums[index_2]=temp;
    }
    void sortColors(vector<int>& nums) {
        //三指针法分别指向0，1，2
        int size=nums.size();
        int p_zero=0;
        int p_one=0;
        int p_two=size;
        while(p_one<p_two){
            if(nums[p_one]==1){
                p_one++;
            }
            else if(nums[p_one]==0){
                
                swap(nums,p_one,p_zero);
                p_zero++;
                p_one++;
            }
            else{
                p_two--;
                swap(nums,p_one,p_two);
            }
        }
    }
};