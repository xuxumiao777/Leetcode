class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res;
        for(long long a=1;a<INT_MAX;a*=2)
            for(long long b=a;b<INT_MAX;b*=3)
                for(long long c=b;c<INT_MAX;c*=5)
                    res.push_back(c);
        sort(res.begin(),res.end());
        return res[n-1];
    }
};