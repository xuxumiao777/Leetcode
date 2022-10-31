class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()){
            return 0;
        }
        int size=intervals.size();
        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){return a[1]<b[1];});
        int num_removed=0,prev=intervals[0][1];
        for(int j=1;j<size;j++){
            if(intervals[j][0]<prev){
                num_removed++;
            }
            else{
                prev=intervals[j][1];
            }

        }
        return num_removed;


    }
};