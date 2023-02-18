#include <iostream>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i, j,maxi = 0;
        vector<int> S(128, 0);
        int len = s.size();
        for(i = 0, j = 0; j < len; j++){
            S[s[j]]++;
            while(S[s[j]] > 1){
                S[s[i]]--;
                i++;
            }
            maxi = max(maxi, j - i + 1);
        }
        return maxi;
    }
    
};
//review
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int right=0;
        int temp=0;
        unordered_map<char,int> hashmap;
        int max_len=0;
        while(right<s.size()){
            //until now no repeat element in the window
            if(hashmap.find(s[right])==hashmap.end()){
                hashmap[s[right]]=right;
                //cout<<left<<" "<<right<<endl;
                max_len=max(max_len,right-left+1);
                right++;
            }
            //repeat element occurs
            else{
                //cout<<right<<endl;
                //max_len=max(max_len,right-left);
                //cout<<max_len<<endl;
                temp=left;
                //cout<<s[right]<<" :"<<hashmap[s[right]]<<endl;
                left=hashmap[s[right]]+1;
                for(int i=temp;i<left;i++){
                    hashmap.erase(s[i]);
                }
                hashmap[s[right]]=right;
                right++;
                
            }
            
        }
        return max_len;
    }
};