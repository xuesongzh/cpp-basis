#include <array>
#include <cstdlib>
#include <ctime>
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
    static void* operator new(size_t size);
    static void operator delete(void* pHead);
    //分配内存次数的统计,new的次数
    static int newCnt;
    static int mallocCnt;  // malloc的次数
 private:
    A* next;
    static A* memoryAddr;  //总是指向一块可以分配出去的内存首地址
    static int trunkCnt;   //一次分配多少倍的该类的内存
};

//静态变量的定义
int A::newCnt = 0;
int A::mallocCnt = 0;
A* A::memoryAddr = nullptr;
int A::trunkCnt = 5;  //一次分配5倍的该类内存作为内存池子的大小

void* A::operator new(size_t size) {
    A* tmplink;
    if (memoryAddr == nullptr) {
        //为空，申请一大块内存
        size_t realSize = trunkCnt * size;  //申请trunkCnt倍的内存
        memoryAddr = reinterpret_cast<A*>(new char[realSize]);
        tmplink = memoryAddr;
        //把分配出来的这一大块5小块内存要彼此链接起来，供以后使用
        while (tmplink != &memoryAddr[trunkCnt - 1]) {
            tmplink->next = tmplink + 1;
            tmplink++;
        }
        tmplink->next = nullptr;
        ++mallocCnt;
    }

    tmplink = memoryAddr;
    //寻找下一次new使用的内存块
    memoryAddr = memoryAddr->next;
    ++newCnt;
    return tmplink;
}

void A::operator delete(void* pHead) {
    //让要释放内存空间的内存块指向下一次分配的内存块，将闲置内存链接起来
    (static_cast<A*>(pHead))->next = memoryAddr;
    //将要释放内存的指针指向下一块要分配的内存。链接在一起。
    memoryAddr = static_cast<A*>(pHead);
    //这种内存不属于真正回收，并没有归还给操作系统。还是归程序管理的。
}

int main(void) {
    clock_t start, end;
    start = clock();
    for (int i = 0; i < 50000000; i++) {
        A* p1 = new A();
        printf("内存地址为=%p\n", p1);
    }
    end = clock();
    cout << "申请new分配内存的次数为" << A::newCnt << endl;
    cout << "申请malloc内存的次数为" << A::mallocCnt << endl;
    cout << "用时（ms）=" << end - start << endl;

    //  申请new分配内存的次数为50000000
    //  申请malloc内存的次数为10000000
    //  用时（ms）=6764ms

    system("pause");
    return 0;
}

/*
 *(1)内存池要解决什么问题？？
 *	1.减少malloc的调用次数(分配内存的次数)，意味着减少对内存的浪费
 *	2.减少malloc的调用次数，提高程序的运行效率，但是提高不明显
 *内存池的实现原理：
 *	1.使用malloc申请一大块内存，减少malloc申请内存的次数，当需要内存的时候，一点一点的分配给程序。
 *	2.当大块内存快用光的时候，再申请一大块内存按照小块分配给程序。
 *主要目的：减少内存浪费，提高运行效率
 *
 *(2)针对一个类的实现演示代码
 *针对一个类的内存池，使用new和delete重载实现
 *
 *
 */