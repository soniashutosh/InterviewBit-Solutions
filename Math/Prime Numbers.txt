vector<int> Solution::sieve(int A) {
    vector<bool> isPrime(A+1, true);
    isPrime[0] = isPrime[1] = false;
    
    for(int i=2;i*i<=A;i++) {
        if(isPrime[i]) {
            for(int j=2;i*j <= A;j++) {
                isPrime[i*j] = false;
            }
        }
    }
    
    vector<int> res;
    for(int i=2;i<=A;i++) {
        if(isPrime[i]) {
            res.push_back(i);
        }
    }
    return res;
}
