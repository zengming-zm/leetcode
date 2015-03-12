class Solution {
public:

    vector<vector<int> > solution(int n){
        vector<vector<int> > result = vector<vector<int> >(n,  vector<int>(n, 0));

        int j = 1;
        int num = n;
        int start_row = -1;
        int start_col = -1;
        
        while ( num > 0 ){
            ++start_row;
            ++start_col;
            if ( num == 1 ){
                result[start_row][start_col] = j;
                ++j;
                num -= 2;
                continue;
            }
            // top: left -> right
            for ( int i = 0; i < num; ++i ){
                result[start_row][start_col+i] = j;
                ++j;
            }
            
            // right: top-bottom
            for ( int i = 1; i < num; ++i ){
                result[start_row+i][start_col+num-1] = j;
                ++j;
            }
            
            //bottom: right-left
            for( int i = num-2; i >= 0; --i ){
                result[start_row+num-1][start_col+i] = j;
                ++j;
            }

            //left: bottom - top
            for ( int i = num-2; i > 0; --i ){
                result[start_row+i][start_col] = j;
                ++j;
            }
            num -= 2;
        }
        return result;
    }
    
    vector<vector<int> > generateMatrix(int n) {
        return solution(n);
        
    }
};