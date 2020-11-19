#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include <memory>
#include <set>
#include <map>
#include <list>
#include <array>

using namespace std;

void *operator new(size_t size)
{
	return  malloc(size);
}

void *operator new[](size_t size)
{
	return  malloc(size);
}

void operator delete(void *p)
{
	free(p);
}

void operator delete[](void *p)
{
	free(p);
}


class A
{
public:
	A()
	{
		cout << "������A�Ĺ��캯��" << endl;
	}

	~A()
	{
		cout << "������A����������" << endl;
	}
public:
	
	
};

int main(void)
{
	//(1)
	int *p1 = new int(123);
	delete p1;

	char*p2 = new char[100];
	delete[]p2;
	//�������д��ȫ��operator new[] operator delete[]��

	A *a1 = new A();
	delete a1;

	A *a2 = new A[10];
	delete[]a2;
	
	system("pause");
	return 0;
}

/*
*(1)����ȫ��operator new operator delete����
*�������������operator new delete���������������ڲ������غ�����
*2019��11��29��21:08:25
* Sunrise�ڶ���������ѧ�ڶ���ѧ¥1121ʵ����

*
*/