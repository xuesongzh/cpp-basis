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
    //�����ڴ������ͳ��,new�Ĵ���
    static int newCnt;
    static int mallocCnt;  // malloc�Ĵ���
 private:
    A* next;
    static A* memoryAddr;  //����ָ��һ����Է����ȥ���ڴ��׵�ַ
    static int trunkCnt;   //һ�η�����ٱ��ĸ�����ڴ�
};

//��̬�����Ķ���
int A::newCnt = 0;
int A::mallocCnt = 0;
A* A::memoryAddr = nullptr;
int A::trunkCnt = 5;  //һ�η���5���ĸ����ڴ���Ϊ�ڴ���ӵĴ�С

void* A::operator new(size_t size) {
    A* tmplink;
    if (memoryAddr == nullptr) {
        //Ϊ�գ�����һ����ڴ�
        size_t realSize = trunkCnt * size;  //����trunkCnt�����ڴ�
        memoryAddr = reinterpret_cast<A*>(new char[realSize]);
        tmplink = memoryAddr;
        //�ѷ����������һ���5С���ڴ�Ҫ�˴��������������Ժ�ʹ��
        while (tmplink != &memoryAddr[trunkCnt - 1]) {
            tmplink->next = tmplink + 1;
            tmplink++;
        }
        tmplink->next = nullptr;
        ++mallocCnt;
    }

    tmplink = memoryAddr;
    //Ѱ����һ��newʹ�õ��ڴ��
    memoryAddr = memoryAddr->next;
    ++newCnt;
    return tmplink;
}

void A::operator delete(void* pHead) {
    //��Ҫ�ͷ��ڴ�ռ���ڴ��ָ����һ�η�����ڴ�飬�������ڴ���������
    (static_cast<A*>(pHead))->next = memoryAddr;
    //��Ҫ�ͷ��ڴ��ָ��ָ����һ��Ҫ������ڴ档������һ��
    memoryAddr = static_cast<A*>(pHead);
    //�����ڴ治�����������գ���û�й黹������ϵͳ�����ǹ�������ġ�
}

int main(void) {
    clock_t start, end;
    start = clock();
    for (int i = 0; i < 50000000; i++) {
        A* p1 = new A();
        printf("�ڴ��ַΪ=%p\n", p1);
    }
    end = clock();
    cout << "����new�����ڴ�Ĵ���Ϊ" << A::newCnt << endl;
    cout << "����malloc�ڴ�Ĵ���Ϊ" << A::mallocCnt << endl;
    cout << "��ʱ��ms��=" << end - start << endl;

    //  ����new�����ڴ�Ĵ���Ϊ50000000
    //  ����malloc�ڴ�Ĵ���Ϊ10000000
    //  ��ʱ��ms��=6764ms

    system("pause");
    return 0;
}

/*
 *(1)�ڴ��Ҫ���ʲô���⣿��
 *	1.����malloc�ĵ��ô���(�����ڴ�Ĵ���)����ζ�ż��ٶ��ڴ���˷�
 *	2.����malloc�ĵ��ô�������߳��������Ч�ʣ�������߲�����
 *�ڴ�ص�ʵ��ԭ��
 *	1.ʹ��malloc����һ����ڴ棬����malloc�����ڴ�Ĵ���������Ҫ�ڴ��ʱ��һ��һ��ķ��������
 *	2.������ڴ���ù��ʱ��������һ����ڴ水��С����������
 *��ҪĿ�ģ������ڴ��˷ѣ��������Ч��
 *
 *(2)���һ�����ʵ����ʾ����
 *���һ������ڴ�أ�ʹ��new��delete����ʵ��
 *
 *
 */