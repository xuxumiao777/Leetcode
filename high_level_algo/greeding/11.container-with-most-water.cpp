class Solution {
public:
    int maxArea(vector<int>& height) {
        int size=height.size();
        int left=0;
        int right=size-1;
        int max_area=0;
        int area_now=0;
        while(left<=right){
            area_now=min(height[left],height[right])*(right-left);
            max_area=max(max_area,area_now);
            height[left]>height[right]?right--:left++;

        }
        return max_area;
    }
};