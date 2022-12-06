class Solution {
public:
    int m_size=0;
    vector<vector<char>> m_board; 
    void init(vector<vector<char>> board){
        m_size=board.size();
        m_board=board;
    }
    bool isValid(int row,int col,char ch){
        for(int i=0;i<m_size;i++){
            if((i!=col)&&(m_board[row][i]==ch)){
                return false;
            }
        }
        for(int i=0;i<m_size;i++){
            if(i!=row&&m_board[i][col]==ch){
                return false;
            }
        }
        for(int i=(row/3)*3;i<(row/3)*3+3;i++){
            for(int j=(col/3)*3;j<(col/3)*3+3;j++){
                if(i!=row&&j!=col&&m_board[i][j]==ch){
                    return false;
                }
            }
        }
        return true;
    }
    bool backtracking(){
        for(int row=0;row<m_size;row++){
            for(int col=0;col<m_size;col++){
                if(m_board[row][col]=='.'){
                    for(char ch='1';ch<='9';ch++){
                       if(isValid(row,col,ch)){
                            m_board[row][col]=ch;                            
                            if(backtracking()==true){
                                return true;
                            }
                            m_board[row][col]='.';
                       } 
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        init(board);
        backtracking();
        board=m_board;
        //return backtracking();
    }
};
