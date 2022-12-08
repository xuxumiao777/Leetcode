class Solution {
public:
    string reverseStr(string s, int k) {
    
        for(int i = 0; i < s.size(); i += k * 2) {
            reverse(s.begin() + i, s.size() - i < k ? s.end() : s.begin() + i + k);
        }
        return s;
    
    }
};