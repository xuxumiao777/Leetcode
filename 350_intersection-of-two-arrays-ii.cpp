class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> hashmap;
        vector<int> result;
        //do iteration to summary how many times every num has;
        for(auto num1:nums1){
            hashmap[num1]++;
        }
        //if it still has the num2,then --the number,and push back to result
        for(auto num2:nums2){
            if(hashmap[num2]>0){
                result.push_back(num2);
                hashmap[num2]--;

            }

        }
        return result;

    }
};