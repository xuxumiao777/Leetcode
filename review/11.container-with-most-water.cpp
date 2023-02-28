class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int left = 0;
        int right = size - 1;
        int maxarea = 0;
        int temparea = 0;
        while(left <= right){
            temparea = min(height[left],height[right])*(right - left);
            maxarea = max(maxarea, temparea);
            height[left] < height[right] ? left++ : right--;
        }
        return maxarea;
    }
};