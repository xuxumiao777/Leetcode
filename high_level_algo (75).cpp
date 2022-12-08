class Solution {
    public:
    int countSubstrings(string s) {
        int n = s.length();
        int ans = 0;
        for (int center = 0; center < n; center++) {
            ans += expand(s, center, center) + expand(s, center, center + 1);
        }
        return ans;
    }

    int expand(string s, int left, int right) {
        int ans = 0;
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            ans++;
            left--;
            right++;
        }
        return ans;
    }
};