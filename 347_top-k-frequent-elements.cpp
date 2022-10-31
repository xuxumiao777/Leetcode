class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hashmap;
        for(auto num:nums){
            hashmap[num]++;
        }
        vector<int> res;
        res.reserve(k);
        priority_queue<pair<int, int>> pq;
        for (auto it : hashmap)
            pq.push({it.second, it.first});
        for (int i = 0; i < k; ++i) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};