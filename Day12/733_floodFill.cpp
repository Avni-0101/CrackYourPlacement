class Solution {
public:

    void recc(vector<vector<int>>& image, int i, int j, int base_color, int color)
    {
        if(i<0 || j<0)  return;
        if(i>=image.size() || j>=image[0].size()) return;
        if(image[i][j]==color)  return;
        if(image[i][j]!=base_color) return;

        image[i][j]=color;

        recc(image,i-1,j,base_color,color);
        recc(image,i+1,j,base_color,color);
        recc(image,i,j-1,base_color,color);
        recc(image,i,j+1,base_color,color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int base_color = image[sr][sc];
        
        recc(image,sr,sc,base_color,color);
        
        return image;
    }
};