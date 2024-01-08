
char convertToLower(char t) {
    if(t>='a' and t<='z') {
        return t-'a'+'A';
    }
    return t;
}

bool isAplhaNumeric(char t) {
    return ((t>='a' and t<='z') or (t>='A' and t<='Z') or (t>='0' and t<='9'));
}

int Solution::isPalindrome(string str) {
    int n = str.size();
    int i = 0, j = n-1;
    while(i<=j) {
        // check str[i] and str[j] is AplhaNumeric
        if(!isAplhaNumeric(str[i])) {
            i++;
            continue;
        }
        if(!isAplhaNumeric(str[j])) {
            j--;
            continue;
        }
        
        // convert default to upper case letter for ignoring cases
        char t1 = convertToLower(str[i]), t2 = convertToLower(str[j]);
        if(t1!=t2) {
            return 0;
        }
        i++; 
        j--;
    }
    return 1;
}
