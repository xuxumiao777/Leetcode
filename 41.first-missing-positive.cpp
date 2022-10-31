class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int> hashmap;
        int res;
        for(auto num:nums){
            hashmap[num]++;
        }
        for(int i=1;i<=nums.size();i++){
            if(hashmap[i]==0){
                res=i;
                return res;
            }
        }
        return nums.size()+1;


    }
};
//原地hash
// author:rmokerone
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != i + 1) {
                if (nums[i] <= 0 || nums[i] > nums.size() || nums[i] == nums[nums[i] - 1])
                    break;
                // 将nums[i] 放置到对应位置上[1,2,3...]
                int idx = nums[i] - 1;
                nums[i] = nums[idx];
                nums[idx] = idx + 1;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != (i + 1)) {
                return (i + 1);
            }
        }
        return (nums.size() + 1);
    }
};

作者：liweiwei1419
链接：https://leetcode.cn/problems/first-missing-positive/solution/tong-pai-xu-python-dai-ma-by-liweiwei1419/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。