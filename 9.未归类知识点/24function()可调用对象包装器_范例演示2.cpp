#include <cstdlib>
#include <functional>
#include <iostream>

using namespace std;

void myCallBack(int value, const std::function<void(int)>& f) {
    f(value);
}

void runfunction(int value) {
    cout << "value=" << value << endl;
}

int main(void) {
    //Ð¡°¸ÀýÑÝÊ¾
    for (int i = 0; i < 10; ++i) {
        myCallBack(i, runfunction);
    }
    system("pause");
    return 0;
}