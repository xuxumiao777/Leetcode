class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int result=0;
        int row=board.size();
        int col=board[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]=='X'){
                    result++;
                    int i_new=i;
                    int j_new=j;
                    while(i_new<row&&board[i_new][j]=='X'){
                        board[i_new][j]='.';
                        i_new++;
                    }
                    j_new++;
                    while(j_new<col&&board[i][j_new]=='X'){
                        board[i][j_new]='.';
                        j_new++;
                    }                    
                }
            }
        }
        return result;
    }
};
