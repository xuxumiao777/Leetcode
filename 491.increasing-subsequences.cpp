class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    void backtracking(vector<int> &nums,int startindex){
        if(path.size()>=2){
            res.push_back(path);
            //return;
        }

        unordered_map<int,int> hashmap;
        for(int i=startindex;i<nums.size();i++){
            if((path.empty()&&hashmap[nums[i]]==0)||((!path.empty()&&nums[i]>=path.back())&&hashmap[nums[i]]==0)){
                hashmap[nums[i]]++;
                cout<<hashmap[nums[i]];
                path.push_back(nums[i]);
                backtracking(nums,i+1);
                path.pop_back();
            }
            else{
                continue;
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
//树层去重题
        backtracking(nums,0);
        return res;
    
    }
};
