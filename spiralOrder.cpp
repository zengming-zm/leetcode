class Solution {
public:
    vector<int> solution(vector<vector<int> > &matrix){
        vector<int> result;
        int m = matrix.size();
        if ( m == 0 ){
            return result;
        }
        int n = matrix[0].size();
        if ( n == 0 ){
            return result;
        }
        
        int layer = min(m, n) / 2 + 1;
        
        int startX = -1;
        int startY = -1;
        while ( m > 0 && n > 0 ){
            startX += 1;
            startY += 1;
            if ( m == 1 ){
                for ( int i = startX; i < startX+n; ++i ){
                    result.push_back(matrix[startY][i]);
                }
                --m;
                continue;
            }
            if ( n == 1 ){
                for ( int i = startY; i < startY + m; ++i ){
                    result.push_back(matrix[i][startX]);
                }
                --n;
                continue;
            }
            
            //top: left -> right
            for ( int i = startX; i < startX+n; ++i ){
                result.push_back(matrix[startY][i]);
            }
            // right: top -> bottom 
            for ( int i = startY+1; i < startY+m; ++i ){
                result.push_back(matrix[i][startX+n-1]);
            }
            // bottom: right -> left
            for ( int i = startX+n-2; i >= startX; --i ){
                result.push_back(matrix[startY+m-1][i]);
            }
            //right: bottom -> top
            for ( int i = startY+m-2; i >= startY+1; --i ){
                result.push_back(matrix[i][startX]);
            }
            m -= 2;
            n -= 2;
        }
        return result;
    }

    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        return solution(matrix);
    }
};