class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row;
        unordered_set<char> col;
        unordered_set<char> block;
        //check every row
        for(int i=0;i<9;i++){
            row.clear();
            col.clear();
            block.clear();
            for(int j=0;j<9;j++){

                if(row.count(board[i][j])>0){
                    return false;
                }
                else if(board[i][j]!='.'){
                    row.insert(board[i][j]);
                }
                if(col.count(board[j][i])>0){
                    return false;
                }
                else if(board[j][i]!='.'){
                    col.insert(board[j][i]);
                }                
                if(block.count(board[i/3*3+j/3][i%3*3+j%3])>0){
                    return false;
                }
                else if(board[i/3*3+j/3][i%3*3+j%3]!='.'){
                    block.insert(board[i/3*3+j/3][i%3*3+j%3]);
                }                
            }           
        }
        return true;

    }
};