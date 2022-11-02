class Solution {
public:
    void death_or_alive(int row,int col,vector<vector<int>> old_board,vector<vector<int>>& next_board){
        int m=old_board.size();
        int n=old_board[0].size();
        int iter_start_row,iter_end_row,iter_start_col,iter_end_col;
        row-1>=0?iter_start_row=row-1:iter_start_row=0;
        row+1<=m-1?iter_end_row=row+1:iter_end_row=m-1;
        col-1>=0?iter_start_col=col-1:iter_start_col=0;
        col+1<=n-1?iter_end_col=col+1:iter_end_col=n-1;
        int num_alive=0;
        
        if(old_board[row][col]==1){
            for(int i=iter_start_row;i<=iter_end_row;i++){
                for(int j=iter_start_col;j<=iter_end_col;j++){
                    if(old_board[i][j]==1){
                        num_alive++;
                    }
                }
            }
            if(num_alive<3){
                next_board[row][col]=0;
            }
            else if(num_alive>4){
                next_board[row][col]=0;
            }
        }
        if(old_board[row][col]==0){
            for(int i=iter_start_row;i<=iter_end_row;i++){
                for(int j=iter_start_col;j<=iter_end_col;j++){
                    if(old_board[i][j]==1){
                        num_alive++;
                    }
                }
            }
            if(num_alive==3){
                next_board[row][col]=1;
            }
        }
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> next_board(board);
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                death_or_alive(i,j,board,next_board);
            }
        }
        board=next_board;
    }
};
