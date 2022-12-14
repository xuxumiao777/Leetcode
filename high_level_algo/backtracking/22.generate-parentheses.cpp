class Solution {
public:
    vector<string> res;
    int m_size;
    string path;
    void init(int n){
        m_size=n;
    }

    void backtracking(int left_bracket_num,int right_bracket_num){
        if(left_bracket_num+right_bracket_num==2*m_size){
            res.push_back(path);
        }
        if(left_bracket_num<=right_bracket_num){
            left_bracket_num++;
            path.push_back('(');
            backtracking(left_bracket_num,right_bracket_num);
            path.pop_back();
            left_bracket_num--;
        }
        else{
            if(left_bracket_num<m_size){
                left_bracket_num++;
                path.push_back('(');
                backtracking(left_bracket_num,right_bracket_num);
                path.pop_back();
                left_bracket_num--;
            }
            if(right_bracket_num<m_size){
                right_bracket_num++;
                path.push_back(')');
                backtracking(left_bracket_num,right_bracket_num);
                path.pop_back();
                right_bracket_num--;                
            }
            
        }

    }
    vector<string> generateParenthesis(int n) {
        init(n);
        backtracking(0,0);
        return res;


        //设计思路，第一个一定是左括号，最后一个一定是右括号，未匹配的左括号（前面括号已经匹配）的左边不能有右括号，右边必须有相应的右括号。

    }
};