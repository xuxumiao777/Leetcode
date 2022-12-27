class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int size=grid.size();
        vector<int> west;
        vector<int> south;
        int max_ele_west=0;
        int max_ele_south=0;
        for(int i=0;i<size;i++){
            max_ele_west=0;
            max_ele_south=0;
            for(int j=0;j<size;j++){
                max_ele_west=max(max_ele_west,grid[i][j]);
                max_ele_south=max(max_ele_south,grid[j][i]);
            }
            west.push_back(max_ele_west);
            south.push_back(max_ele_south);
        }
        int res=0;
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(min(south[j],west[i])>grid[i][j])
                    res+=(min(south[j],west[i])-grid[i][j]);
            }
        }
        return res;
    }
};