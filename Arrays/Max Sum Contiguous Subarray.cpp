vector<int> Solution::plusOne(vector<int> &A) {
    vector<int> res;
    int n = A.size();
    if(n==0) return res;
    
    int carry = 1;
    for(int i=n-1;i>=0;i--) {
        int rem = (A[i]+carry)%10;
        carry = (A[i]+carry)/10;
        res.push_back(rem);
    }
    if(carry != 0) {
        res.push_back(carry);
    }
    // Some inputs contains leading zeroes in test-case 
    // so we need to remove trailing zeroes from our result ...
    for(int i=res.size()-1;i>=0;i--) {
        if(res[i] == 0) {
            res.pop_back();
        }
        else{
            break;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}
