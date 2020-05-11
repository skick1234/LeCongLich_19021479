#include <iostream>
#include <cmath>
using namespace std;

void update(int *a,int *b) {
    *a = *a+*b;
    *b = abs(*a-*b-*b);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    cin >> a >> b;
    update(pa, pb);
    cout << a << endl << b;

    return 0;
}
