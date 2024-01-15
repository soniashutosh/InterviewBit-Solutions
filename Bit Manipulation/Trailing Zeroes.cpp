int Solution::solve(int A) {
    int count = 0;
    while ((A & 1) == 0 && A > 0) {
        count++;
        A >>= 1;
    }

    return count;
}