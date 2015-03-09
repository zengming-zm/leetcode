class Solution {
public:
    /*
     n = positive
     negative?!!!!!!!
     */
    double solution(double x, int n){
        if ( n == 0 ){
            return 1;
        }
        else if ( n == 1 ){
            return x;
        }
        else if ( n < 0 ){
            return solution(1.0/x, -n);
        }
        else if ( n % 2 == 0 ){
            double result = solution(x, n/2);
            return result * result;
        }
        else if ( n % 2 == 1 ){
            double result = solution(x, n/2);
            return result * result * x;
        }
        
    }
    double pow(double x, int n) {
        // reduce some time consumption cases, 1, -1, 0
        if ( abs(x) == 1 && n % 2 == 0 ){
            return 1;
        }
        if ( x == -1 && n % 2 == 1 ) {
            return -1;
        }
        
        if ( x == 0 ){
            return 0;
        }
        return solution(x, n);
    }
};