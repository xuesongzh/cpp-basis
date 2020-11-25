#include <array>
#include <cstdlib>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>

using namespace std;
class A {
 public:
    void myFunction() {
        A* a = new A();
        delete a;
    }
    static void* operator new[](size_t size);
    static void operator delete[](void* pHead);

    A() {
        cout << "这是类A的构造函数" << endl;
    }
    ~A() {
        cout << "这是类A的析构函数" << endl;
    }
};

void* A::operator new[](size_t size) {
    A* p1 = (A*)malloc(size);
    return p1;
}

void A::operator delete[](void* pHead) {
    free(pHead);
}

int main(void) {
    A* p1 = new A[3]();
    delete[] p1;

    system("pause");
    return 0;
}

/*
 * 重载类中的new[] delete[]运算符
 * operator new[]和operator delete[]被调用1次，但是构造函数和析构函数被调用3次
 *
 * 为什么调用operator new函数分配7个字节？
 * 每个对象占用1个字节，多分配4个字节
 * 分配了一个整形用于存储数组元素的个数 3
 *
 p1 = 0x0057d3a0		operator new()分配的地址，这是分配的向后的7个字节
 p1 = 0x0057d3a4		返回的地址
 0x0057D3A0  03 00 00 00 cd cd cd fd fd fd fd dd
 0x0057D3AC  dd dd dd dd 10 a8 ac 25 dd dd 00 80
*/