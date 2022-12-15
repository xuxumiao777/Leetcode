bool cmp(vector<int> p1,vector<int> p2){
    if(p1[0]==p2[0]){
        return p1[1]<p2[1];
    }
    return p1[0]>p2[0];
}
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort (people.begin(), people.end(), cmp);
        vector<vector<int>> que;
        for (int i = 0; i < people.size(); i++) {
            int position = people[i][1];
            que.insert(que.begin() + position, people[i]);
        }
        return que;
    }    
};