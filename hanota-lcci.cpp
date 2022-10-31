class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        int size=A.size();
        move(size,A,B,C);
        

    }
    void move(int n,vector<int>& A, vector<int>& B, vector<int>& C){
        if(n==1){
            C.push_back(A.back());
            A.pop_back();
        }
        else{
            move(n-1,A,C,B);
            C.push_back(A.back());
            A.pop_back();
            move(n-1,B,A,C);            

        }
    }
};
