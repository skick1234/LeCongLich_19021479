#include <bits/stdc++.h>
using namespace std;

int main() {
    string number;
    cin >> number;
    bool breakwhile = false;
    int begin_id = 0;
    while (!breakwhile && begin_id < number.size()) {
        int max_id = begin_id;
        for (int i = begin_id; i < number.size(); i++)
            max_id = number[max_id] < number[i] ? i : max_id;
        if (begin_id != max_id) {
            char tmp = number[max_id];
            number[max_id] = number[begin_id];
            number[begin_id] = tmp;
            breakwhile = true;
        }
        begin_id++;
    }
    cout << number;
    return 0;
}