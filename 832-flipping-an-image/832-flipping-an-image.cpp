class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(int i=0;i<image.size();i++){
            int k=0,j=image.size()-1;
            while(k<j){
                swap(image[i][k],image[i][j]);
                image[i][k]^=1;
                image[i][j]^=1;
                k++; j--;
            }
            if(k==j) image[i][k]^=1;
        }
        return image;
    }
};