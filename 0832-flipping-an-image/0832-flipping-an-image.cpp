class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        int row = 0;
        for(int c=0;c<n;c++) {
            int i = 0, j = n -1;
            while(i < j) {
                int temp = image[row][i];
                image[row][i] = image[row][j];
                image[row][j] = temp;
                i++;
                j--;
            }
            row++;
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(image[i][j] == 0) image[i][j] = 1;
                else image[i][j] = 0;
            }
        }
        return image;
    }
};