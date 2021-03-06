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
    static void* operator new(size_t size);
    static void operator delete(void* pHead);

    A() {
        cout << "这是类A的构造函数" << endl;
    }

    ~A() {
        cout << "这是类A的析构函数" << endl;
    }
};

void* A::operator new(size_t size) {
    A* p1 = (A*)malloc(size);
    return p1;
}

void A::operator delete(void* pHead) {
    free(pHead);
}

int main(void) {
    A* a1 = new A();  //调用自己写的operator new函数
    delete a1;        //调用自己的operator delete函数
    //如果想调用系统的new和delete函数  ::new A();  ---::是全局作用域
    A* a1 = ::new A();
    system("pause");
    return 0;
}

/*
 *(1)重载类中的new delete运算符
 *调用顺序：1. 调用operator new函数分配内存空间
 *		 2。调用构造函数构建对象
 *		 .......做一系列操作
 *		 3.调用析构函数做对象释放前的准备工作
 *		 4.调用operator delete释放内存空间
 *
 *
 */