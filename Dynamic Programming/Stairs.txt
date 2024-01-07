int Solution::climbStairs(int A) {
    vector<int> dp(A+1,0);
    //base case 
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    
    // dp[i] represents number of ways to reach to i 
    // so it will be sum number of ways to reach to i-1 and number of ways to reach i-2
    for(int i=3;i<=A;i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[A];
}

