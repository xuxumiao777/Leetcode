class Solution {
public:
    bool isPalindrome(int x) {
         if(x<0){
             return false;
         }
         int z=x;
         vector<int> v;
         while(z>9){
             v.push_back(z%10);
             z=(z-z%10)/10;
         }
         v.push_back(z);
         long len=v.size();
         for(int i=0;i<len;i++){
             if(v[i]!=v[len-1-i]){
                 return false;
             }
             
         }
         return true;

    }
};