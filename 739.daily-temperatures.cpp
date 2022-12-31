class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> d;
        for (int i = 0; i < n; i++) {
            while (!d.empty() && temperatures[d.top()] < temperatures[i]) {
                int idx = d.top();
                ans[idx] = i - idx;
                d.pop();
            }
            d.push(i);
        }
        return ans;
    }
};