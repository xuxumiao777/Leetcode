class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size=flowerbed.size();
        if(size==0){
            return false;
        }
        if(size==1&&n>1){
            return false;
        }
        if(size==1&&n==1){
            if(flowerbed[0]==0)
                return true;
            else 
                return false;
        }
        int prev=-1;
        int size_zero=0;
        int num_flower=0;
        for(int i=0;i<size;i++){
            if(flowerbed[i]==1){
                if(prev<0){
                
                
                    num_flower+=(i)/2;
                    
                    
                }
                else{
                    size_zero=i-prev-1;
                
                    num_flower+=abs(size_zero-1)/2;
                }
                prev=i;
            }
        }

        //last sequence of zero
        if(prev<0){
            return (size+1)/2>=n;
        }
        if(size-prev-1>1){
            num_flower+=(size-prev-1)/2;
        }
        if(num_flower<n){
            return false;
        }
            

        return true;
    }

    
};