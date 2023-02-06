class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left=newInterval[0];
        int right=newInterval[1];
        int size=intervals.size();
        int left_pos=0;
        int right_pos=size-1;
        while(left_pos<size){
            if(left>intervals[left_pos][1]){
                left_pos++;
                continue;
            }
            else{
                break;
            }
        }
        while(right_pos>=0){
            if(right<intervals[right_pos][0]){
                right_pos--;
                continue;
            }
            else{
                break;
            }
        }
        cout<<left_pos;
        cout<<right_pos;
        vector<vector<int>> res;
        if(right_pos==-1){
            res.push_back(newInterval);
            for(int i=0;i<size;i++){
                res.push_back(intervals[i]);
            }
            return res;
        }
        for(int i=0;i<left_pos;i++){
            res.push_back(intervals[i]);
        }
        if(left_pos>right_pos){
            res.push_back(newInterval);
            for(int i=right_pos+1;i<size;i++){
                res.push_back(intervals[i]);
            }            
            return res;
        }
        res.push_back({min(intervals[left_pos][0],left),max(right,intervals[right_pos][1])});
        for(int i=right_pos+1;i<size;i++){
            res.push_back(intervals[i]);
        }
        return res;
    }
};