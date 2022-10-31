class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int size=ratings.size();
        if(size<2){
            return size;
        }
        vector<int> cookie(size,1);
        for(int i=0;i<size-1;i++){
            if(ratings[i+1]>ratings[i]){
                cookie[i+1]=cookie[i]+1;
            }
        }
        for(int j=size-1;j>0;j--){
            if(ratings[j-1]>ratings[j]){
                cookie[j-1]=max(cookie[j]+1,cookie[j-1]);
            }
        }
        //return 0;
        return accumulate(cookie.begin(),cookie.end(),0);
    }
};