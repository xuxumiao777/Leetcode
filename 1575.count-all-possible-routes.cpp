class Solution {
private:
    static constexpr int mod = 1000000007;
    vector<vector<int>> f;
    
public:
    int dfs(const vector<int>& locations, int pos, int finish, int rest) {
        if (f[pos][rest] != -1) {
            return f[pos][rest];
        }
        
        f[pos][rest] = 0;
        if (abs(locations[pos] - locations[finish]) > rest) {
            return 0;
        }
        
        int n = locations.size();
        for (int i = 0; i < n; ++i) {
            if (pos != i) {
                if (int cost = abs(locations[pos] - locations[i]); cost <= rest) {
                    f[pos][rest] += dfs(locations, i, finish, rest - cost);
                    f[pos][rest] %= mod;
                }
            }
        }
        if (pos == finish) {
            f[pos][rest] += 1;
            f[pos][rest] %= mod;
        }
        return f[pos][rest];
    }
    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        f.assign(locations.size(), vector<int>(fuel + 1, -1));
        return dfs(locations, start, finish, fuel);
    }
};

