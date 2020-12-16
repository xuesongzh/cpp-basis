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

class embeddedPointer {
 public:
    int m_i;
    int m_j;

 public:
    struct obj {
        struct obj *next;  //指向本身结构的指针，next就是一个嵌入式指针
    };                     //写在class内部，外部不可见，只能在类内部使用
};

//二：内存池代码的改进
//单独为内存池技术来写一个类

//专门的内存池类
class myallocator  //必须保证应用本类的类的sizeof()不少于4字节，否则会崩溃或者报错；
{
 public:
    //分配内存接口
    void *allocate(size_t size) {
        obj *tmplink;
        if (memoryAddr == nullptr) {
            //为空，申请一大块内存
            size_t realsize = trunkCnt * size;  //申请m_sTrunkCout这么多倍的内存
            memoryAddr = (obj *)malloc(realsize);
            tmplink = memoryAddr;

            //把分配出来的这一大块内存（5小块），彼此链接起来，供以后使用
            for (int i = 0; i < trunkCnt - 1; ++i) {
                tmplink->next = (obj *)((char *)tmplink + size);
                tmplink = tmplink->next;
            }
            tmplink->next = nullptr;
        }
        tmplink = memoryAddr;
        memoryAddr = memoryAddr->next;
        return tmplink;
    }

    //释放内存接口
    void deallocate(void *phead) {
        ((obj *)phead)->next = memoryAddr;
        memoryAddr = (obj *)phead;
    }

 private:
    //写在类内的结构，这样只让其在类内使用
    struct obj {
        struct obj *next;  //这个next就是个嵌入式指针
    };
    int trunkCnt = 5;  //一次分配5倍的该类内存作为内存池子的大小
    obj *memoryAddr = nullptr;
};

//------------------------
#define DECLARE_POOL_ALLOC()                   \
 public:                                       \
    static myallocator myalloc;                \
    static void *operator new(size_t size) {   \
        return myalloc.allocate(size);         \
    }                                          \
    static void operator delete(void *phead) { \
        return myalloc.deallocate(phead);      \
    }

#define IMPLEMENT_POOL_ALLOC(classname) myallocator classname::myalloc;

class A {
    DECLARE_POOL_ALLOC()

 public:
    int m_i;
    int m_j;  //为了保证sizeof(A)凑够4字节，老师演示时定义了两个int成员变量；
};
IMPLEMENT_POOL_ALLOC(A)

void func() {
    A *mypa[100];
    for (int i = 0; i < 15; ++i) {
        mypa[i] = new A();
        mypa[i]->m_i = 12;
        mypa[i]->m_j = 15;

        printf("%p\n", mypa[i]);
    }
    for (int i = 0; i < 15; ++i) {
        delete mypa[i];
    }
}

int main(void) {
    //嵌入式指针的使用
    embeddedPointer mytest;
    cout << sizeof(mytest) << endl;                // 8
    embeddedPointer::obj *ptem;                    //定义一个嵌入式指针
    ptem = (embeddedPointer::obj *)&mytest;        //把对象首地址赋值给ptem指针
    cout << sizeof(ptem->next) << endl;            // 4
    cout << sizeof(embeddedPointer::obj) << endl;  // 4
    ptem->next = nullptr;

    //内存池代码改进
    func();

    system("pause");
    return 0;
}

/*
 *(1)嵌入式指针embedded pointer
 *一般应用在内存池相关代码中，使用嵌入式指针有个前提：类A对象的sizeof不小于4个字节
 *
 *嵌入式指针的工作原理：借用类A对象所占用的内存空间的前4个字节，这4个字节指针用来链接内存块。
 *一旦分配出去，这4个字节的指针占用的位置就不需要保存了，可以存储数据。
 *
 *嵌入式指针代码演示
 *
 *(2)内存池代码改进
 *
 *
 *
 */