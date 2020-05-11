#include <vector>
#include <fstream>
using namespace std;

int main() {
    ifstream inp;
    ofstream out;
    inp.open("input.txt");
    out.open("output.txt");

    int n, input, mi, ma, s = 0, c = 0;
    inp >> n;
    vector<int> v(10, 0);

    for (int i = 0; i < n; i++) {
        inp >> input;
        v[input]++;
    }

    for (int i = 0; i < 10; i++)
        out << i << ':' << v.at(i) << endl;

    inp.close();
    out.close();
    return 0;
}