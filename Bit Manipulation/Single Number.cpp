int Solution::singleNumber(const vector<int> &A) {
    int res = 0;
    for(auto ele: A) {
        res = res ^ ele;
    }
    return res;
}
