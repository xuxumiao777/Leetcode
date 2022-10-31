class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int size=numbers.size();
        int i=0,j=size-1;
        vector<int> result;
        while(i<j){
            int sum=numbers[i]+numbers[j];
            if(sum==target){
                break;
            }
            if(sum<target){
                i++;
            }
            else{
                j--;
            }
            
        }
        result.push_back(i+1);
        result.push_back(j+1);
        return result;

    }
};