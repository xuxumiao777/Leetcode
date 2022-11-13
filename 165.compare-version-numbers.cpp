class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream stream1;
        stream1<<version1;
        stringstream stream2;
        stream2<<version2;
        int res=0;
        vector<int> arr1;
        vector<int> arr2;
        char c;
        while(stream1>>res>>c){
            arr1.push_back(res);
        }
        stream1>>res;
        if(res!=0){
            arr1.push_back(res);
        }
        while(stream2>>res>>c){
            arr2.push_back(res);            
        }
        stream2>>res;
        if(res!=0){
            arr2.push_back(res);
        }
        

        for(int i=0;i<min(arr1.size(),arr2.size());i++){
            if(arr1[i]>arr2[i]){
                return 1;
            }
            if(arr1[i]<arr2[i]){
                return -1;
            }
        }
        if(arr1.size()>arr2.size()){
            for(int i=arr2.size();i<arr1.size();i++){
                if(arr1[i]!=0){
                    return 1;
                }
            }
        }
        if(arr1.size()<arr2.size()){
            for(int i=arr1.size();i<arr2.size();i++){
                if(arr2[i]!=0){
                    return -1;
                }
            }
        }
        return 0;
    }
};