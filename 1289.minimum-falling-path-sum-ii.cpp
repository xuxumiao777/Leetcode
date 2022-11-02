class Solution {
public:
    int min_val(vector<int> &array,int index_skip,int size){
        int res=array[0];
        if(index_skip==-1){
            res=array[0];
            for(int i=1;i<size;i++){
                res=min(res,array[i]);
            }              
        }
        else if(index_skip>0){
            res=array[0];
            for(int i=0;i<size;i++){
                if(i==index_skip){
                    continue;
                }
                else{
                    res=min(res,array[i]);
                }
                
            }
        }
        else if(index_skip==0){
            res=array[1];
            for(int i=1;i<size;i++){
                res=min(res,array[i]);
            }            
        }
        //cout<<res<<endl;
        return res;
    } 
    int minFallingPathSum(vector<vector<int>>& grid) {
        int size=grid.size();
        for(int row=size-2;row>=0;row--){
            for(int col=0;col<size;col++){
                grid[row][col]+=min_val(grid[row+1],col,size);
            }
        }
        return min_val(grid[0],-1,size);
    }
};
