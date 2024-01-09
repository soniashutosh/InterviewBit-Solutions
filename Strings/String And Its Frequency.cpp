string Solution::solve(string str) {
    vector<int> countChar(26,0);
    for(int i=0;i<str.size();i++) {
        countChar[str[i]-'a']++;
    }
    string res = "";
    for(int i=0;i<str.size();i++) {
        if(countChar[str[i]-'a'] > 0) {
            res += str[i] + to_string(countChar[str[i]-'a']);
            countChar[str[i]-'a'] = 0;
        }
    }
    return res;
}