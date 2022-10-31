class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int result=0;
        int size=nums1.size();
        unordered_map<int,int> hashmap;
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                hashmap[nums1[i]+nums2[j]]++;
            }
        }
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(hashmap[-nums3[i]-nums4[j]]>0){
                    result+=hashmap[-nums3[i]-nums4[j]];
                }
            }
        }
        return result;        


    }
};