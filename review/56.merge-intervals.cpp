class Solution {
public:
    static bool comp(vector<int>& A,vector<int>& B){
        return A[0]<B[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        vector<vector<int>>res;
        vector<int> temp=intervals[0];
        for(auto cur:intervals){
            if(cur[0]>temp[1]){
                res.push_back(temp);
                temp=cur;
            }
            else{
                temp[1]=max(temp[1],cur[1]);
            }
        }
        res.push_back(temp);
        return res;
    }
};