#include <iostream>
using namespace std;

string decimal_to_binary(long number) {
    string bin = "";
    do {
        bin += to_string(number%2);
        number /= 2;
    } while (number >= 1);
    int len = bin.length();
    int n = len-1;
    for(int i=0;i<(len/2);i++){
        swap(bin[i],bin[n]);
        n = n-1;
    }
    return bin;
}

int main() {
    long n;
    cin >> n;
    cout << decimal_to_binary(n);
    return 0;
}