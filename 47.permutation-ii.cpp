class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    void backtracking(vector<int>& nums,vector<int>& used){
        if(path.size()==nums.size()){
            res.push_back(path);
            return;
        }
        unordered_map<int,int> hashmap;
        for(int i=0;i<nums.size();i++){
            if(used[i]==1){
                continue;
            }
            if(hashmap[nums[i]]==0){
                hashmap[nums[i]]++;
                used[i]=1;
                path.push_back(nums[i]);
                backtracking(nums,used);
                path.pop_back();
                used[i]=0;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> used(nums.size(),0);
        backtracking(nums,used);
        return res;
    }
};
