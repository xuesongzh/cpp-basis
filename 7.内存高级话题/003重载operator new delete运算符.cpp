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

class A
{
public:
	void myFunction()
	{
		A*a = new A();
		delete a;
	}
	static void *operator new(size_t size);
	static void operator delete(void*pHead);

	A()
	{
		cout << "������A�Ĺ��캯��" << endl;
	}
	~A()
	{
		cout << "������a����������" << endl;
	}
public:
	
};

void* A::operator new(size_t size)
{
	A*p1 = (A*)malloc(size);
	return p1;
}

void A::operator delete(void* pHead)
{

	free(pHead);
}




int main(void)
{
	A*a1 = new A();//�����Լ�д��operator new����
	delete a1;//�����Լ���operator delete����
	//��������ϵͳ��new��delete����  ::new A();  ---::��ȫ��������
	system("pause");
	return 0;
}

/*
*(1)�������е�new delete�����
*����˳��1. ����operator new���������ڴ�ռ�
*		 2�����ù��캯����������
*		 .......��һϵ�в���
*		 3.�������������������ͷ�ǰ��׼������
*		 4.����operator delete�ͷ��ڴ�ռ�
*
*(2)
*
*(3)
*2019��11��29��18:26:40
* Sunrise�ڶ���������ѧ�ڶ���ѧ¥1121ʵ����

*
*/