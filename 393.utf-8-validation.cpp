class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int size=data.size();
        if(size==1){
            if(((data[0]>>7)&1)==0){
                return true;
            }
            else{
                return false;
            }
        }
        int size_one=0;
        int j=0;
        for(int i=0;i<size;i++){
            j=7;
            size_one=0;
            if(data[i]==0){
                continue;
            }
            if(data[i]==255){
                return false;
            }
            //cout<<data[i]<<endl;
            while(((data[i]>>j)&1)==1){
                size_one++;
                j--;
            }

            if(size_one==0){
                continue;
            }
            else if(size_one==1){
                return false;
            }
            else if(size_one>=5){
                return false;
            }
            else{
                size_one--;
            }
            if(size_one>size-i-1){
                return false;
            }
            else{
                while(size_one){
                    size_one--;
                    i++;
                    if(((data[i]>>7)&1)!=1||((data[i]>>6)&1)!=0){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};