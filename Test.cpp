#include <bits/stdc++.h>
using namespace std;

int main() {
	string num;
	cin >> num;

	for (int i = 0; i < num.size(); ++i) {
		int min = i;
		for (int j = i + 1; j < num.size(); ++j)
			if ((i ? true : num[j] > 0) && num[min] >= num[j])
				min = j;
		if (min > i && num[i] > num[min]) {
			swap(num[i], num[min]);
			break;
		}
	}
	cout << stoi(num);
}