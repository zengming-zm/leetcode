class Solution {
public:

    int solution(uint32_t n){
        n = ( n & 0x55555555 ) + ( (n >> 1) & 0x55555555 );
        n = ( n & 0x33333333 ) + ( (n >> 2) & 0x33333333 );
        n = ( n & 0x0F0F0F0F ) + ( (n >> 4) & 0x0F0F0F0F );
        n = ( n & 0x00FF00FF ) + ( (n >> 8) & 0x00FF00FF );
        n = ( n & 0x0000FFFF ) + ( (n >> 16) & 0x0000FFFF );
        
        return (int)n;
    }

    int hammingWeight(uint32_t n) {
        return solution(n);
    }
};