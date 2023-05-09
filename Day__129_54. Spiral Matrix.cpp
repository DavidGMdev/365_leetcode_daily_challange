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

// More compact version

class Solution {
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    const int END = -101;
    bool valid( int i , int j , int n , int m , vector<vector<int>>& matrix , const int END ){
        return ( i > -1 && j > -1 && i < n && j < m && matrix[i][j] != END );
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size() , m = matrix[0].size();
        int i = 0 , j = 0 , iter = 0 ;
        ans.push_back(matrix[i][j]);
        matrix[i][j] = END;
        while(ans.size() != n*m){
            while( valid( i + dx[iter] , j + dy[iter] , n , m , matrix , END ) ) {
                i += dx[iter] , j += dy[iter];
                ans.push_back(matrix[i][j]);
                matrix[i][j] = END;
            }
            iter++;
            iter%=4;
        }
        
        return ans;
    }
};

