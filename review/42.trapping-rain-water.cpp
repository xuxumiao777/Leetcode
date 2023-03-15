class Solution {
public:
    int trap(vector<int>& height) {
        int size=height.size();
        vector<int> leftmax(size+2,0);
        vector<int> rightmax(size+2,0);
        int res=0;
        //cout<<height[size]<<endl;
        for(int i=0;i<size;i++){
            leftmax[i+1]=max(leftmax[i],height[i]);
        }
        for(int i=size-1;i>=0;i--){
            rightmax[i+1]=max(rightmax[i+2],height[i]);
        }
        for(int i=1;i<=size;i++){
            res+=(min(leftmax[i],rightmax[i])-height[i-1]);
        }
        return res;
    }
};