#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T, typename U>
void TestFunction(T &t, U &u) {
    cout << "--这是函数泛化版本--" << endl;
}

//全特化版本 t=int，u=doubel
template <>  //全特化，所以为空
void TestFunction(int &t, double &u) {
    cout << "--这是int double类型的特化版本--" << endl;
}

void TestFunction(int &t, double &u) {
    cout << "这是testFunction的重载函数" << endl;
}

int main(void) {
    //函数模板全特化
    const char *p = "jisuanjiz";
    int i = 1200;
    TestFunction(p, i);  // t=const char* &

    double d = 23.344;
    TestFunction(i, d);  //调用int double 的特化版本
    //如果有重载函数，优先调用重载函数，而不去调用特例话的函数

    system("pause");
    return 0;
}

/*
 *(1)函数模板全特化
 *全特化函数实际上等价于实例化一个函数模板，并不是等价于一个函数重载
 *
 *特化函数遇上重载函数优先调用重载函数
 *
 *
 *
 */