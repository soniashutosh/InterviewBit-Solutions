int m=1e9+7;
int Solution::chordCnt(int A) {
    vector<long long int> dp(2*A+2,0);
    dp[0]=1;
    dp[1]=0;
    for(int i=2;i<=2*A;i+=2)
    {
        for(int j=2;j<=i;j++)
        {
            // dp[i] = numsber of ways of joining j-2 points on left * number of ways of joining i-j points on right
            dp[i] += (dp[i-j]%m)*(dp[j-2]%m);
            dp[i] %= m;
        }
    }
    return dp[2*A]%m;
}