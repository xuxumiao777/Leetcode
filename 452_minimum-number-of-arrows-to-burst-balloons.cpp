class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](vector<int>&a,vector<int>&b){return a[1]<b[1];});
        int size=points.size();
        if(size<=1){
            return size;
        }
        
        int arrow=points[0][1];
        int num_arrow=1;
        for(int i=1;i<size;i++){
            if(points[i][0]>arrow){
                arrow=points[i][1];
                num_arrow++;

            }


        }
        return num_arrow;

    }
};