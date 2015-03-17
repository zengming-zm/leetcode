class Solution {
public:
    /*
    4 4 3 3 3 3 2 2 in the mid 
    3 3 3 2 2 2 2 2 left
    2 2 2 2 2 3 3 3 right
    */
    
    vector<int> solution(int A[], int n, int target){
        vector<int> result = vector<int>(2, -1);
        
        int start = 0;
        int end = n-1;
        while ( start < end ){
            int mid = start + (end - start)/2;
            if ( A[mid] < target ){
                start = mid + 1;
                continue;
            }
            else{
                end = mid;
            }
        }
        int lower = (A[start] == target) ? start : -1;
        if ( lower == -1 ){
            return result;
        }
        
        start = 0;
        end = n-1;
        while ( start < end ){
            int mid = start + ( end - start ) / 2 + 1;
            if ( A[mid] > target ){
                end = mid - 1;
            }
            else{
                start = mid;
            }
        }
        int upper = (A[end] == target) ? end : lower;
        result[0] = lower;
        result[1] = upper;
        
        return result;
    }
    
    vector<int> searchRange(int A[], int n, int target) {
        return solution(A, n, target);
    }
};