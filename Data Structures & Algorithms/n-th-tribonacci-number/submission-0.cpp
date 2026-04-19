class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 1;
        vector<int> T(n+1);
        T[0] = 0;
        T[1] = 1;
        T[2] = 1;
        for(int t = 3; t <= n; t++){
            T[t] = T[t-3] + T[t-2] + T[t-1];
        }
        return T[n];
    }
};