#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

void myFunction(int i) {
    cout << "i=" << i << endl;
}

int main(void) {
    vector<int> myVector = {10, 20, 30, 40};
    int sum = 0;
    for_each(myVector.begin(), myVector.end(), [&sum](int value) {
        cout << "value=" << value << endl;
        sum += value;
    });
    cout << "sum=" << sum << endl;  // 100
    system("pause");
    return 0;
}
/*
 * for_each()使用lambda表达式
 */