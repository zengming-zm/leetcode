class Solution {
public:
    void solution(vector<vector<int> > &matrix){
        int n = matrix.size();
        if ( n == 0 ) return;
        int m = matrix[0].size();
        
        bool zero_row = false;
        bool zero_col = false;
        for ( int i = 0; i < n; ++i ){
            if ( matrix[i][0] == 0 ){
                zero_col = true;
                break;
            }
        }
        for ( int i = 0; i < m; ++i ){
            if ( matrix[0][i] == 0 ){
                zero_row = true;
                break;
            }
        }
        
        for ( int i = 1; i < n; ++i ){
            for ( int j = 1; j < m; ++j ){
                if ( matrix[i][j] == 0 ){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for ( int i = 1; i < n; ++i ){
            for ( int j = 1; j < m; ++j ){
                if ( matrix[i][0] == 0 || matrix[0][j] == 0 ){
                    matrix[i][j] = 0;
                }
            }
        }
        
        if ( zero_row ){
            for ( int i = 0; i < m; ++i ){
                matrix[0][i] = 0;
            }
        }
        if ( zero_col ){
            for ( int i = 0; i < n; ++i ){
                matrix[i][0] = 0;
            }
        }
        
        
    }
    void setZeroes(vector<vector<int> > &matrix) {
        solution(matrix);
    }
};