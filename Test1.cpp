#include <bits/stdc++.h>
using namespace std;

string run(string num, int k) {
	int n = num.length();
	if (k >= n) return "0";
	string s = "";
	for (char ch: num) {
		while (s.length() && s.back() > ch && k) s.pop_back(), k--;
		if (s.length() || ch != '0') s.push_back(ch);
	}
	while (s.length() && k--)
		s.pop_back();
	return s.length() != 0 ? s : "0";
}

int main() {
	string str;
	int k;
	cin >> str >> k;
	cout << run(str, k);
	return 0;
}