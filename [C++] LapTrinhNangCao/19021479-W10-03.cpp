#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    vector<int> v;
    int n, inp, b, e;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> inp;
        v.push_back(inp);
    }
    cin >> b;
    v.erase(v.begin()+b-1);
    cin >> b >> e;
    v.erase(v.begin()+b-1, v.begin()+e-1);
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
        cout << v.at(i) << " ";
    return 0;
}
