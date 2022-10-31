class Solution {
public:
    string solveEquation(string equation) {
        istringstream ss(equation);
        int sgn = 1, dir = -1, num=0, xNum=0, tmpNum;
        for (char ch; ss >> ch; )
        {
            if (ch == '+') sgn = 1;
            else if (ch == '-') sgn = -1;
            else if (ch == '=') dir = sgn = 1;
            else if (ch == 'x') xNum -= dir * sgn;
            else {
                ss.unget();//把ch中的数读出来，相当于保留流中的刚刚输出的内容
                ss >> tmpNum;
                cout<<tmpNum<<endl;
                if (ss.peek() == 'x') {
                    ss.get();
                    xNum -= dir * sgn * tmpNum;
                }
                else num += dir * sgn * tmpNum;
            }
        }
        return xNum ? "x=" + to_string(num / xNum) : num ? "No solution" : "Infinite solutions";
    }
};