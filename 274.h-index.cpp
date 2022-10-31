class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end(),greater<>());
        
        int max_size=citations.size();
        if(max_size==0){
            return 0;
        }
        for(int i=0;i<max_size;i++){
            
            if(citations[i]<i+1){
                return i;
            }
        }
        return max_size;
    }
};