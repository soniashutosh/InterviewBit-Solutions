#define mod 1000000007
int Solution::solve(int A) 
{
    int n=A;
    long long int c[n+1][n+1] = {0};
    
    // calculate nCr 
    // formula used (n)C(r) = (n-1)C(r) + (n-1)C(r-1)
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= i; j++){
            if(i == j || j == 0){
                c[i][j] = 1;
                continue;
            }
            c[i][j] = ((c[i-1][j]%mod) + (c[i-1][j-1]%mod))%mod;
        }
    }
    long long int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<=n; i++){
        /*
            here we are trying to height of tree 
            we will get log(2)i -> floor(height) it means for last level completely full its h and for others its h-1
            element in last level = i -  2^0 + ... 2^h considering above factor that height is already one less for tree having last level not completely full
            last level left side will have all the elements if its greater than 2^(h)/2  {total possible elements in last level} otherwise left element for last level
            right side will have (total_elements - leftside - 1)
        */
        int h = log10(i)/log10(2); 
        int p = i-((1<<h)-1);
        if(p>=(1<<h-1))
            p = 1<<h-1;
        int L = (1<<(h-1))-1+p;
        dp[i] = (c[i-1][L]*((dp[L]*dp[i-1-L])%mod))%mod;
    }
    return dp[n];
}