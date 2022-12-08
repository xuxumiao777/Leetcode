// bool greatersort(pair<int,int> a,pair<int,int> b){
//     return a.first>b.first;
// }
class Solution {

public:
    static bool greatersort(pair<int,int> a,pair<int,int> b){
        return a.first>b.first;
    }
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int,int>> temp;
        for(int i=0;i<score.size();i++){
            temp.push_back(make_pair(score[i],i));
        }
        sort(temp.begin(),temp.end(),greatersort);
        vector<string> res(score.size());

        for(int i=0;i<score.size();i++){
            if(i==0){
                res[temp[i].second]="Gold Medal";
            }
            if(i==1){
                res[temp[i].second]="Silver Medal";
            }
            if(i==2){
                res[temp[i].second]="Bronze Medal";
            }
            else if(i>=3){
                res[temp[i].second]=to_string(i+1);
            }
        }
        return res;
    }
};