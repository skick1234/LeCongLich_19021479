#include <thread>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
//    for (int i = 0; i < 3; i++) {
//        cout << "This the hello " << i << endl;
//    }
    vector<thread> threads;
    for (int i = 0; i < 4; i++) {
        threads.push_back(thread([i]{
            cout << "This the hello " << i << endl;
        }));
    }
    for (thread& t: threads) t.join();
    return 0;
}
