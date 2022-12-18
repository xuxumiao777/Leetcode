class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        vector<vector<int>> res;
        int left=intervals[0][0];
        int right=intervals[0][1];
        if(intervals.size()==1){
            res.push_back({left,right});
            return res;
        }
        for(int i=1;i<intervals.size();i++){
            if(i==intervals.size()-1){
                if(intervals[i][0]>right){
                    res.push_back({left,right});
                    res.push_back({intervals[i][0],intervals[i][1]});
                }
                else{
                    res.push_back({left,max(right,intervals[i][1])});
                }
                
            }
            else if(intervals[i][0]>right){
                
                res.push_back({left,right});
                left=intervals[i][0];
                right=intervals[i][1];
            }
            //右区间合并
            else{
                right=max(intervals[i][1],right);
            }
        }
        return res;
    }
};