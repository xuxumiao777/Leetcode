class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size=nums.size();
        int i=0,j=1;
        if(size==0){
            return 0;
        }
        if(size==1){
            return 1;
        }
        for(j=0;j<size;j++){
            if(nums[i]!=nums[j]){
                i++;
                nums[i]=nums[j];
            }
            
            
            
                
            
        }
        return ++i;

    }
};