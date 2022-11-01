class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int height=triangle.size();
        for(int height_cur=height-2;height_cur>=0;height_cur--){
            for(int i=0;i<=triangle[height_cur].size()-1;i++){
                triangle[height_cur][i]+=min(triangle[height_cur+1][i],triangle[height_cur+1][i+1]);
            }
        }
        return triangle[0][0];
    }
};
