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