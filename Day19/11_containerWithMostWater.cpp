class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int start=0,end=n-1;
        int area=0;
        while(start<end)
        {
            int length = end - start;
            int breadth = height[start]<height[end]?height[start] : height[end];

            int temp = length * breadth;

            area = max(area,temp);
            
            height[start]<height[end]?start++:end--;
        }
        return area;
    }
};