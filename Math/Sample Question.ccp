int Solution::solve(int A, int B) {
    long long MOD = 1e7;
    long long res = (A%MOD + B%MOD)%MOD;
    return res;
}
