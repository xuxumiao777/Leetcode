class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    void backtracking(vector<int> &nums,int startindex){
        if(startindex>=nums.size()){
            return;
        }
        int temp=nums[startindex];
        for(int i=startindex;i<nums.size();i++){
            if(i==startindex||nums[i]!=temp){
                path.push_back(nums[i]);
                res.push_back(path);
                temp=nums[i];
                backtracking(nums,i+1);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        backtracking(nums,0);
        res.push_back({});
        return res;
    }
};
