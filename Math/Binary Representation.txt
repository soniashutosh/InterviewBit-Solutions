string Solution::findDigitsInBinary(int A) {
    if(A==0) return "0";
    string res = "";
    while(A > 0) {
        int t = A & 1;
        A = A>>1;
        res = to_string(t) + res;
    }
    return res;
}
