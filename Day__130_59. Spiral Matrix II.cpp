// build on top of previous day problem / challange
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        const int END = -101;
        vector<vector<int>> matrix(n, vector<int>(n, END) );     
        int i = 0 , j = 0 , val = 1 ;
        matrix[i][j] = val++;
        while(val <= n*n){
            while(j+1 < n  && matrix[i][j+1] == END)  matrix[i][++j] = val++;
            while(i+1 < n  && matrix[i+1][j] == END)  matrix[++i][j] = val++;
            while(j-1 > -1 && matrix[i][j-1] == END)  matrix[i][--j] = val++;
            while(i-1 > -1 && matrix[i-1][j] == END)  matrix[--i][j] = val++;
        }
        return matrix;
    }
};
