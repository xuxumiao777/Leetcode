class Solution {
public:
    int len = 1;
    string res;
    string longestPalindrome(string s) {
        //中心扩展算法
        //从每一个位置mid出发，向两边扩散
        int maxLeft = 0;//记录最长回文子串的起点
        int maxRight = 0;//记录最长回文子串的终点
        int maxlen = 0;//记录最长回文子串的长度
        for(int mid = 0; mid < s.size(); ++mid){
            int left = mid - 1;
            int right = mid + 1;
            //向左侧扩展，直到超过边界或遇到与中心字符不等跳出while循环
            while(left >= 0 && s[left] == s[mid]){
                left--;//left字符与mid字符一致，继续左移
                len++;//与mid字符一致，回文长度+1
            }
            //向右侧扩展，直到超过边界或遇到与中心字符不等跳出while循环
            while(right <= s.size() - 1 && s[right] == s[mid]){
                right++;//right字符与mid字符一致，继续左移
                len++;//与mid字符一致，回文长度+1
            }
            //同时向左右两侧扩展
            while(left >= 0 && right <= s.size() - 1 && s[left] == s[right]){
                //注意此处，在最后一次循环中，即最长回文子串索引为：i~j，此时的left=i-1，right=j+1
                left--;
                right++;
                len += 2;
            }
            if(len > maxlen){
                maxLeft = left;
                maxRight = right;
                maxlen = len;
            }
            len = 1;
        }
        //返回子串,从pos位开始，长度为len
        return s.substr(maxLeft + 1, maxlen);
    }
};
//review 中心扩展法
class Solution {
public:
    pair<int,int> expandAroundCenter(string &s,int left,int right){
        while(left>=0&&right<s.size()){
            if(s[left]==s[right]){
                left--;
                right++;
            }
            else{
                break;
            }
        }
        return {left+1,right-1};
    }
    string longestPalindrome(string s) {
        int left=0;
        int right=0;
        int left_temp;
        int right_temp;
        for(int i=0;i<s.size();i++){
            auto [left1,right1] = expandAroundCenter(s,i,i);
            auto [left2,right2] = expandAroundCenter(s,i,i+1);
            //cout<<left1<<right1<<endl;
            if(right1-left1>=right2-left2){
                left_temp=left1;
                right_temp=right1;
            }
            else{
                left_temp=left2;
                right_temp=right2;                
            }
            if(right_temp-left_temp>right-left){
                left=left_temp;
                right=right_temp;
            }

        }
        return s.substr(left,right-left+1);
    }
};