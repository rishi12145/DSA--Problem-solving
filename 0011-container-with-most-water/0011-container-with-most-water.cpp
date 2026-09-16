class Solution {
public:
    int maxArea(vector<int>& height) {

        int n = height.size();
        int area = 0;
        int i = 0;
        int j = n-1;

        while(i < j){
            int h = min(height[i], height[j]);
            int width = j-i;

            int current_area = h * width;

            area = max(area, current_area);

            if(height[i] < height[j]){
                i++;
            }

            else{
                j--;
            }
        }
        return area;  
    }
};