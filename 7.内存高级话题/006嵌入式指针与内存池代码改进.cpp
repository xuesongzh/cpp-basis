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
        struct obj *next;  //ָ����ṹ��ָ�룬next����һ��Ƕ��ʽָ��
    };                     //д��class�ڲ����ⲿ���ɼ���ֻ�������ڲ�ʹ��
};

//�����ڴ�ش���ĸĽ�
//����Ϊ�ڴ�ؼ�����дһ����

//ר�ŵ��ڴ����
class myallocator  //���뱣֤Ӧ�ñ�������sizeof()������4�ֽڣ������������߱���
{
 public:
    //�����ڴ�ӿ�
    void *allocate(size_t size) {
        obj *tmplink;
        if (memoryAddr == nullptr) {
            //Ϊ�գ�����һ����ڴ�
            size_t realsize = trunkCnt * size;  //����m_sTrunkCout��ô�౶���ڴ�
            memoryAddr = (obj *)malloc(realsize);
            tmplink = memoryAddr;

            //�ѷ����������һ����ڴ棨5С�飩���˴��������������Ժ�ʹ��
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

    //�ͷ��ڴ�ӿ�
    void deallocate(void *phead) {
        ((obj *)phead)->next = memoryAddr;
        memoryAddr = (obj *)phead;
    }

 private:
    //д�����ڵĽṹ������ֻ����������ʹ��
    struct obj {
        struct obj *next;  //���next���Ǹ�Ƕ��ʽָ��
    };
    int trunkCnt = 5;  //һ�η���5���ĸ����ڴ���Ϊ�ڴ���ӵĴ�С
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
    int m_j;  //Ϊ�˱�֤sizeof(A)�չ�4�ֽڣ���ʦ��ʾʱ����������int��Ա������
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
    //Ƕ��ʽָ���ʹ��
    embeddedPointer mytest;
    cout << sizeof(mytest) << endl;                // 8
    embeddedPointer::obj *ptem;                    //����һ��Ƕ��ʽָ��
    ptem = (embeddedPointer::obj *)&mytest;        //�Ѷ����׵�ַ��ֵ��ptemָ��
    cout << sizeof(ptem->next) << endl;            // 4
    cout << sizeof(embeddedPointer::obj) << endl;  // 4
    ptem->next = nullptr;

    //�ڴ�ش���Ľ�
    func();

    system("pause");
    return 0;
}

/*
 *(1)Ƕ��ʽָ��embedded pointer
 *һ��Ӧ�����ڴ����ش����У�ʹ��Ƕ��ʽָ���и�ǰ�᣺��A�����sizeof��С��4���ֽ�
 *
 *Ƕ��ʽָ��Ĺ���ԭ��������A������ռ�õ��ڴ�ռ��ǰ4���ֽڣ���4���ֽ�ָ�����������ڴ�顣
 *һ�������ȥ����4���ֽڵ�ָ��ռ�õ�λ�þͲ���Ҫ�����ˣ����Դ洢���ݡ�
 *
 *Ƕ��ʽָ�������ʾ
 *
 *(2)�ڴ�ش���Ľ�
 *
 *
 *
 */