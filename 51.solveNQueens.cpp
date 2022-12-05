class Solution {
public:
    int m_size;
    vector<string> m_checkboard;
    vector<vector<string>> m_res;
    void init(int n){
        m_size=n;
        vector<string> checkboard(m_size,string(m_size,'.'));
        m_checkboard=checkboard;
    }
    bool isValid(int row,int col){
        //横向
        for(int i=0;i<m_size;i++){
            if(i!=col&&m_checkboard[row][i]=='Q'){
                return false;
            }
        }
        //纵向
        for(int i=0;i<m_size;i++){
            if(i!=row&&m_checkboard[i][col]=='Q'){
                return false;
            }
        }
        //north-east45度
        int temp_row=row,temp_col=col;
        while((temp_row>=0)&&(temp_col<m_size)){
            if(m_checkboard[temp_row][temp_col]=='Q'){
                return false;
            }
            temp_col++;
            temp_row--;
        }
        temp_row=row;
        temp_col=col;
        //south-west45度
        while((temp_row<m_size)&&(temp_col>=0)){
            if(m_checkboard[temp_row][temp_col]=='Q'){
                return false;
            }
            temp_col--;
            temp_row++;
        }
        //north-west45度
        temp_row=row;
        temp_col=col;
        while((temp_row>=0)&&(temp_col>=0)){
            if(m_checkboard[temp_row][temp_col]=='Q'){
                return false;
            }
            temp_col--;
            temp_row--;
        }
        temp_row=row;
        temp_col=col;
        while((temp_row<m_size)&&(temp_col<m_size)){
            if(m_checkboard[temp_row][temp_col]=='Q'){
                return false;
            }
            temp_col++;
            temp_row++;
        }
        return true;
    }
    void backtracking(int row){
        if(row==m_size){
            m_res.push_back(m_checkboard);
            return;
        }
        for(int i=0;i<m_size;i++){
            if(isValid(row,i)){
                m_checkboard[row][i]='Q';
                backtracking(row+1);
                m_checkboard[row][i]='.';
            }
            else{
                continue;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        init(n);
        backtracking(0);
        return m_res;
    }
};
