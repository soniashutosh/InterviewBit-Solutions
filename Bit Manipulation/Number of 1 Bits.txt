int Solution::numSetBits(unsigned int A) {
    int res = 0;
    // Shift left and check if last bit is 1 or not
    while(A > 0) {
        res += A & 1;
        A = A>>1;
    }
    return res;
}
