#include <bits/stdc++.h>

using namespace std;

string run(string num, int k) {
	vector < char > stk;
	int i = 0, removedCount = 0;

	while (i < num.length() and removedCount < k) {
		if (stk.empty() or num[i] >= stk.back())
			stk.push_back(num[i++]);
		else
			stk.pop_back(), removedCount++;
	}

	while (removedCount++ < k)
		stk.pop_back();

	while (i < num.length())
		stk.push_back(num[i++]);
	int j = 0;
	while (j < stk.size() and stk[j] == '0')
		j++;

	string result(stk.begin() + j, stk.end());

	return result == "" ? "0" : result;
}

int main() {
	string str;
	int k;
	cin >> str >> k;
	cout << run(str, k);
	return 0;
}