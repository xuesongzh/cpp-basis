#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;
class A
{
public:
	int a;
	A(int i) :a(i)
	{
		cout << "A���캯��ִ��" << endl;

	}
	virtual ~A()
	{
		cout << "A��������" << endl;
	}
};
class B1 :public A
{
public:
	int b1;
	B1(int i, int j) :A(i), b1(j)
	{
		cout << "B1���캯��ִ��" << endl;

	}
	virtual ~B1()
	{
		cout << "B1��������" << endl;
	}
};

class B2 :public A
{
public:
	int b2;
	B2(int i, int j) :A(i), b2(j)
	{
		cout << "B2���캯��ִ��" << endl;

	}
	virtual ~B2()
	{
		cout << "B2��������" << endl;
	}
};


class C :public B1, public B2		//�����б�
{
public:
	int c;
	C(int i, int j, int k) :B1(i, j), B2(i, j), c(k)//�Լ��İ汾
	{
		cout << "c���캯��ִ��" << endl;
	}
	//using B1::B1;
	//using B2::B2;
public:
	static  int static_number;//������̬����
public:
	virtual ~C()
	{
		cout << "C��������" << endl;
	}
};

int C::static_number = 10;//��������������ڴ�ռ䣬�����ֵ

void playObject()
{
	;

}

int main(void)
{
	playObject();
	system("pause");
	return 0;
}

/*
*(1)�Ӷ������̳й��캯��
*	���һ��������Ļ����м̳�����ͬ�Ĺ��캯������������Ϊ�ù��캯�������Լ��İ汾��
*
*/