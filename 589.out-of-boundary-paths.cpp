class Solution {
public:
    vector<vector<int>> state;
    //vector<int> coordinate;
    int mod=pow(10,9)+7;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        state.assign(m*n,vector<int>(maxMove+1,0));
        for(int i=0;i<m;i++){
            for(int step=1;step<=maxMove;step++){
                state[coordinate_to_index(i,0,n)][step]++;
                state[coordinate_to_index(i,n-1,n)][step]++;
            }
        }
        for(int i=0;i<n;i++){
            for(int step=1;step<=maxMove;step++){
                state[coordinate_to_index(0,i,n)][step]++;
                state[coordinate_to_index(m-1,i,n)][step]++;
            }
        }
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<state[coordinate_to_index(i,j,n)][3];
        //     }
        //     cout<<";"<<endl;
        // }
        vector<vector<int>> directions;
        vector<int> left={-1,0};
        vector<int> right={1,0};
        vector<int> up={0,1};
        vector<int> down={0,-1};
        directions.push_back(left);
        directions.push_back(right);
        directions.push_back(up);
        directions.push_back(down);
        //cout<<state[1][1];
        for(int step=1;step<=maxMove;step++){
            for(int index=0;index<m*n;index++){
                for(auto dir:directions){
                    int *p;
                    p=index_to_coordinate(index,n);
                    int x=*p+dir[0];
                    int y=*(p+1)+dir[1];
                    if(x>=0&&x<m&&y>=0&&y<n){
                        state[index][step]+=state[coordinate_to_index(x,y,n)][step-1];
                        state[index][step]%=mod;
                        //cout<<"state"<<index<<","<<step<<","<<state[index][step]<<endl;
                    }
                }
            }
        }
        return state[startRow*n+startColumn][maxMove];
    }
    int coordinate_to_index(int x,int y,int n){
        return n*x+y;
    }
    int* index_to_coordinate(int index,int n){
        static int coordinate[2];
        coordinate[0]=index/n;//output the x
        coordinate[1]=index%n; //output the y
        return coordinate;
    }
};
