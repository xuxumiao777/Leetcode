class Solution {
public:
    static int to_minutes(string a){
        int res=0;
        res+=a[4]-'0';
        res+=(a[3]-'0')*10;
        res+=(a[1]-'0')*60;
        res+=(a[0]-'0')*600;

        return res;
    } 

    int findMinDifference(vector<string>& timePoints) {
        int size=timePoints.size();
        vector<int> temp;
        for(int i=0;i<timePoints.size();i++){
            
            temp.push_back(to_minutes(timePoints[i]));
            temp.push_back(to_minutes(timePoints[i])+1440);
        }
        

        sort(temp.begin(),temp.end());
        int res=temp[1]-temp[0];
        for(int i=1;i<2*size-1;i++){
            res=min(res,temp[i+1]-temp[i]);
        }
        return res;
    }
};