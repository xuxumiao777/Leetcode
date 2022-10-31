class Solution {
public:
    bool judgeSquareSum(int c) {
        long right=(int)sqrt(c);
        
        long left=0;
        while(left<=right){
            long sum=left*left+right*right;
            if(sum<c){
                left++;
            }
            else if(sum>c){
                right--;
            }
            else{
                return true;
            }

        }
        return false;

    }
};