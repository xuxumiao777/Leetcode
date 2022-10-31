class Solution {
public:
//     int max(int a,int b){
//         return a>=b?a:b;
//     }
//     int min(int a,int b){
//         return a<=b?a:b;
//     }
//     bool containsNearbyDuplicate(vector<int>& nums, int k) {
//         unordered_map<int,int> hashmap;
//         if(nums.size()==1&&k>=1){
//             return false;
//         }
//         for(int i=0;i<max(nums.size()-k,1);i++){
//             hashmap.clear();
//             for(int j=i;j<=min(i+k,nums.size()-1);j++){
//                 if(hashmap[nums[j]]>0){
//                     return true;

//                 }
//                 hashmap[nums[j]]++;
//             }
//         }
//         return false;

//     }
// };//runtime error(very complex can be O(n2) )
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap;
        for(int i = 0; i < nums.size(); i++){
            if(hashmap.count(nums[i])<=0){
                hashmap[nums[i]]=i;
            }
            else{
                if(i-hashmap[nums[i]]<=k){
                    return true;
                }
                hashmap[nums[i]]=i;
            }

        }
        return false;
    }
};