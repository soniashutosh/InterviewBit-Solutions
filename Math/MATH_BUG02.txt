vector<vector<int> > Solution::squareSum(int A) {
	vector<vector<int> > ans;
	for (int a = 1; a * a <= A; a++) {
		for (int b = a; b * b <= A; b++) {
            long long a1 = a, b1 = b;
			if (a1 * a1 + b1 * b1 == A) {
				vector<int> newEntry; 
				newEntry.push_back(a);
				newEntry.push_back(b);
				ans.push_back(newEntry);
			}
		}
	}
	return ans;
}
