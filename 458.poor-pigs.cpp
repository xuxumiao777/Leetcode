class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int times=minutesToTest/minutesToDie+1;
        return ceil(log(buckets)/log(times)-1e-5);
    }
};