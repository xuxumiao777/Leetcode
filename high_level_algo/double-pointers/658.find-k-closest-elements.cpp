class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int diff=INT_MAX;
        int index;
        for(int i=0;i<arr.size();i++){
            if(abs(arr[i]-x)<diff){
                diff=abs(arr[i]-x);
                index=i;
            }
        }
        int left=index,right=index;
        cout<<left;
        while(right-left<k-1){
            if(left==0){
                right++;
            }
            else if(right==arr.size()-1){
                left--;
            }
            else if(abs(arr[right+1]-x)==abs(arr[left-1]-x)){
                if(left>0){
                    left--;
                }
                else if(right<arr.size()-1){
                    right++;
                }
            }
            else{
                if(abs(arr[right+1]-x)<abs(arr[left-1]-x)){
                    if(right<arr.size()-1){
                        right++;
                    }
                    else{
                        left--;
                    }
                }
                else{
                    if(left>0){
                        left--;
                    }
                    else if(right<arr.size()-1){
                        right++;
                    }
                }
            }
        }
        //cout<<left<<endl;
        //cout<<right<<endl;
        vector<int> res;
        for(int i=left;i<=right;i++){
            res.push_back(arr[i]);
        }
        return res;
    }
};