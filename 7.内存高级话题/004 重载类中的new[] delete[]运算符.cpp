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
	static void *operator new[](size_t size);
	static void operator delete[](void*pHead);

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

void* A::operator new[](size_t size)
{
	A*p1 = (A*)malloc(size);
	return p1;
}

void A::operator delete[](void* pHead)
{

	free(pHead);
}



int main(void)
{
	A*p1 = new A[3];
	delete[]p1;

	system("pause");
	return 0;
}

/*
	�������е�new[] delete[]�����--�ͷ�������ڴ�ռ�
*(1)
*operator new ��operator delete������1�Σ����ǹ��캯������������������3��
*
*ΪΪʲô����operator new��������7���ֽڣ�ÿ������ռ��1���ֽڣ������4���ֽ�
*������һ���������ڴ洢����Ԫ�صĸ��� 3
*
p1 = 0x0057d3a0		operator new()����ĵ�ַ�������Ƿ��������7���ֽ�
p1 = 0x0057d3a4		���صĵ�ַ
0x0057D3A0  03 00 00 00 cd cd cd fd fd fd fd dd 
0x0057D3AC  dd dd dd dd 10 a8 ac 25 dd dd 00 80  

*2019��11��29��18:47:29
* Sunrise�ڶ���������ѧ�ڶ���ѧ¥1121ʵ����

*/