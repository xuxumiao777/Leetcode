class Solution {
public:
    bool check(string &a, string &b) {
        int k = 0;
        for (char c: b)
        if (k < a.size() && c == a[k]) k ++ ;
        return k == (int)a.size();
    }

    int findLUSlength(vector<string>& strs) {
        int ans = -1;
        for (int i = 0; i < strs.size(); i ++ ) {
            bool ok = false;
            for (int j = 0; j < strs.size(); j ++ )
                if (i != j && check(strs[i], strs[j])) {
                    ok = true;
                    break;
                }
            if (!ok) ans = max(ans, (int)strs[i].size());
        }
        return ans;
    }
};