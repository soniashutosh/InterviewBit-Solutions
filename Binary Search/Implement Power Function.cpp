int Solution::pow(int x, int n, int d) {
    if(!x) return 0;
    int isneg = 0;
    if(x<0){
        isneg=1;
        x=-x;
    }
    //n= 2^1+2^2+2^3...=> x^4= X^2.X^2
    long long curr = x;
    long long ans=1;
    int i=0;
    while(n>>i){
        if((n>>i)&1){
            ans=ans*curr%d;
        }
        curr= curr*curr%d;
        i=i+1;
    }
    if(isneg and n%2){
        ans= (-ans+d)%d;
    }
    return ans;
}