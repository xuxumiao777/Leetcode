class Solution {
public:
    bool res=false;
    void backtracking(vector<vector<char>>& board, string& word, int index, vector<vector<bool>>& used, int row, int col){
        //searching upwards
        if(index==1&&row==1&&col==1){
            //cout<<"here"<<endl;
        }
        if(index>word.size()){
            return;
        }
        if(index==word.size()){
            //cout<<row<<col<<endl;
            res=true;
            return;
        }
        if(row>0 && used[row-1][col]==false && word[index]==board[row-1][col]){
            used[row-1][col]=true;
            backtracking(board, word, index+1, used, row-1, col);
            used[row-1][col]=false;
        }
        //downwards searching
        if(row<board.size()-1 && used[row+1][col]==false && word[index]==board[row+1][col]){
            used[row+1][col]=true;
            backtracking(board, word, index+1, used, row+1, col);
            used[row+1][col]=false;
        }
        //left search
        if(col>0 && used[row][col-1]==false && word[index]==board[row][col-1]){
            used[row][col-1]=true;
            backtracking(board, word, index+1, used, row, col-1);
            used[row][col-1]=false;
        }
        //right searching
        if(col<board[0].size()-1 && used[row][col+1]==false && word[index]==board[row][col+1]){
            used[row][col+1]=true;
            backtracking(board, word, index+1, used, row, col+1);
            used[row][col+1]=false;
        }
        return;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<bool>> used(row,vector<bool>(col,false));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]==word[0]){
                    used[i][j]=true;
                    backtracking(board, word, 1, used, i, j);
                    used[i][j]=false;
                }
            }
        }
        return res;
    }
};