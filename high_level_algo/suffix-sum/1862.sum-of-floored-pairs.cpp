class Solution {
public:
    static const int MAXN = 1e5 + 5;
    int mod = 1e9 + 7;
    int cnt[MAXN], sum[MAXN];

    int sumOfFlooredPairs(vector<int>& nums) {
        for (int i : nums) {
            ++cnt[i];
        }
        for (int i = 1; i < MAXN; ++i) sum[i] = sum[i - 1] + cnt[i];
        int ans = 0;
        for (int i = 1; i < MAXN; ++i) {
            for (int j = i, k = 1; j < MAXN; j += i, ++k) {
                int l = j;
                int r = std::min(j + i - 1, MAXN - 1);
                int tot = sum[r] - sum[l - 1];
                ans += 1ll * tot * k % mod * cnt[i] % mod;
                ans %= mod;
            }
        }
        return ans;
    }
};