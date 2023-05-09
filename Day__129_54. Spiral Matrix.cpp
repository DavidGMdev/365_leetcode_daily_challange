// spiral matrix iterative 

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        const int END = -101;
        int i = 0 , j = 0 ;
        int n = matrix.size() , m = matrix[0].size();
        ans.push_back(matrix[i][j]);
        matrix[i][j] = END;
        while(ans.size() != n*m){
            while(j+1 < m && matrix[i][j+1] != END) {
                ans.push_back(matrix[i][++j]);
                matrix[i][j] = END;
            }
            while(i+1 < n && matrix[i+1][j] != END) {
                ans.push_back(matrix[++i][j]);
                matrix[i][j] = END;
            }
            while(j-1 > -1 && matrix[i][j-1] != END) {
                ans.push_back(matrix[i][--j]);
                matrix[i][j] = END;
            }
            while(i-1 > -1 && matrix[i-1][j] != END) {
                ans.push_back(matrix[--i][j]);
                matrix[i][j] = END;
            }
        }
        return ans;
    }
};
/*
for debug !
for( int i = 0 ; i < ans.size() ; i++ ){
    cout << ans[i] << " " ;
}
cout << endl ;
break;
*/
