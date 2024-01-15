/*
    maxLength = max(length(A), length(B))
    Current Time complexity: O(maxLength) Space complexity = O(maxLength)
    whereas we can sort both the string and return A==B 
    in that case time complexity will be O(maxLength*log(maxLength)) and Space complexity = O(1)
*/
int Solution::permuteStrings(string A, string B) {
    unordered_map<char,int> mp;
    int countNotEqual = 0;
    for(auto ele: A) {
        mp[ele]++;
    }
    for(auto ele: B) {
        if(mp.find(ele) != mp.end()) {
            mp[ele]--;
            if(mp[ele] ==  0) {
                mp.erase(ele);
            }
        }
        else {
            countNotEqual++;
        }
    }
    return (countNotEqual==0 && mp.size()==0);
}
