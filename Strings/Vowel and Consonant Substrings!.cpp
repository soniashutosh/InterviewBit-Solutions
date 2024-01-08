
int MOD = 1e9+7;

bool isVowel(char t) {
    return (t=='a' or t=='e' or t=='i' or t=='o' or t=='u');
}

int Solution::solve(string str) {
    int n = str.size();
    if(n==0) return 0;
    
    vector<int> countVowel(n+1,0);
    for(int i=0;i<n;i++) {
        countVowel[i+1] = countVowel[i];
        if(isVowel(str[i])) {
            countVowel[i+1]++;
        }
    }
    
    long long res = 0;
    for(int i=0;i<n;i++) {
        int total_vowel_ahead = (countVowel[n] - countVowel[i+1]);
        if(isVowel(str[i])) {
            int conso = (n-1-i) - total_vowel_ahead;
            res = res%MOD + conso%MOD;
        }
        else {
            res = res%MOD + total_vowel_ahead%MOD;
        }
    }
    return res;
}
