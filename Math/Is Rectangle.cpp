int Solution::solve(int A, int B, int C, int D) {
    if(A==C && B==D || A==B && C==D || A==D && B==C){
        return 1;
    }
    return 0;
}
