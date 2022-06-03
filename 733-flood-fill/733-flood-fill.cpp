class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int start=image[sr][sc];
        if(start==newColor) return image;
        change(image,sr,sc,start,newColor);
        return image;
    }
    void change(vector<vector<int>>& image, int sr, int sc,int start, int newColor){
        if(sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size() ) return;
        else if(image[sr][sc]!=start) return;
        image[sr][sc]=newColor;
        change(image,sr+1,sc,start,newColor);
        change(image,sr,sc+1,start,newColor);
        change(image,sr-1,sc,start,newColor);
        change(image,sr,sc-1,start,newColor);
    }
};