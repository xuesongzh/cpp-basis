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
    for_each(myVector.begin(), myVector.end(), myFunction);  //起始迭代器，结束迭代器，操作

    system("pause");
    return 0;
}
/*
 * for_each()是个函数模板
 */