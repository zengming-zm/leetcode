class Solution {
public:

    void solution(int A[], int low, int mid, int hig){
        while ( mid <= hig ){
            if ( A[mid] == 0 ){
                swap(A[low], A[mid]);
                ++low;
                ++mid;
            }
            else if ( A[mid] == 1 ) {
                ++mid;
            }
            else{
                swap(A[hig], A[mid]);
                --hig;
            }
        }
    }

    void sortColors(int A[], int n) {
        solution(A, 0, 0, n-1);
    }
};