typedef pair<int,int> PII;
class Solution {
public:
    vector<PII> state;
    int mod=pow(10,9)+7;
    int m_length=0;
    vector<vector<int>> directions={{1,0},{1,1},{0,1}};
    int coordinate2index(int x,int y){
        return m_length*x+y;
    }
    int* index2coordinate(int index){
        int p[2];
        p[0]=index/m_length;
        p[1]=index%m_length;
        return p;
    }
    char coordinate2element(int x,int y,vector<string> &board){
        return board[x][y];
    }
    PII num_paths_score(int x,int y,vector<string>& board){
        int max_score=INT_MIN+10000,num_path=0;
        for(auto dir:directions){
            int x_ori=x+dir[0];
            int y_ori=y+dir[1];
            //max_score=INT_MIN+10000;
            //num_path=0;
            if(x_ori>=0&&x_ori<m_length&&y_ori>=0&&y_ori<m_length){
                if(state[coordinate2index(x_ori,y_ori)].first>max_score){
                    max_score=state[coordinate2index(x_ori,y_ori)].first%mod;
                    num_path=state[coordinate2index(x_ori,y_ori)].second%mod;
                }
                else if(state[coordinate2index(x_ori,y_ori)].first==max_score){
                    num_path+=state[coordinate2index(x_ori,y_ori)].second%mod;
                }
            }

        }
        PII res;
        res.first=max_score;
        res.second=num_path;
        cout<<max_score;
        cout<<num_path<<endl;
        return res;
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        vector<int> res;
        m_length=board.size();
        //state initialization
        state.assign(m_length*m_length,{0,0});
        for(int x=0;x<m_length;x++){
            for(int y=0;y<m_length;y++){
                if(coordinate2element(x,y,board)=='X'){
                    state[coordinate2index(x,y)]={INT_MIN,0};
                }
                else if(coordinate2element(x,y,board)=='S'){
                    state[coordinate2index(x,y)]={0,1};
                }
            }
        }
        //initialization finished and start search with memorization
        for(int x=m_length-1;x>=0;x--){
            for(int y=m_length-1;y>=0;y--){
                if(coordinate2element(x,y,board)=='X'||coordinate2element(x,y,board)=='S'){
                    continue;
                }
                else if(coordinate2element(x,y,board)=='E'){
                    state[coordinate2index(x,y)].first=num_paths_score(x,y,board).first;
                    state[coordinate2index(x,y)].second=num_paths_score(x,y,board).second;
                }
                else{
                    int ele=coordinate2element(x,y,board)-'0';
                    cout<<ele<<endl;
                    //cout<<
                    state[coordinate2index(x,y)].first=num_paths_score(x,y,board).first+ele;
                    state[coordinate2index(x,y)].second=num_paths_score(x,y,board).second;                    
                }
            }
        }
        vector<int> result;
        //int temp=state[0].first%mod;
        result.push_back(state[0].first>0?state[0].first%mod:0);
        result.push_back(state[0].second%mod);
        return result;
    }
};
