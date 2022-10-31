class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result;

        while(columnNumber){
            columnNumber--;
            char ch=columnNumber%26+65;
            result=ch+result;
            columnNumber=columnNumber/26;
        }
        //int size=result.size();
        //result[size-1]=result[size-1]+1;
        //result="AAA";
        //char ch='B';

        return result;

    }
};
//注意最开始的对应是从一开始的所以要columnNumber--;
