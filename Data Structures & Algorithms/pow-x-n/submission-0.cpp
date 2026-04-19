class Solution {
public:
    double myPow(double x, int n) {
        if(x == 1) return 1;
        if(n == 0) return 1;
        long long N;
        if(n < 0){
            x = 1/x;
            N = - ((long long) n);
        }
        else {
            N = n;
        }
        double result = 1.0;
        double current_product = x;
        while(N > 0) {
            if(N % 2 == 1) {
                result *= current_product;
            }
            current_product *= current_product;
            N /= 2;
        }
        return result;
    }
};