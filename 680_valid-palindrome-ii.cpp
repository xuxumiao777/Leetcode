class Solution {
private:
    bool isPalindrome(const string& s, int l, int r) {
        while (l <= r) {
            if (s[l] == s[r]) {
                ++l;
                --r;
            } else {
                return false;
            } 
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int n = s.size(), l = 0, r = n - 1;
        while (l <= r) {
            if (s[l] == s[r]) {
                ++l;
                --r;
            } else {
                return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
            }
        }
        return true;
    }
};