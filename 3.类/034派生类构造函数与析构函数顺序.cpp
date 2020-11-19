#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;
class A
{
public:
	int a;
	A(int i):a(i)
	{
		cout << "A���캯��ִ��" << endl;

	}
	virtual ~A()
	{
		cout << "A��������" << endl;
	}
};
class B1:public A
{
public:
	int b1;
	B1(int i,int j):A(i),b1(j)
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


class C:public B1,public B2		//�����б�
{
public:
	int c;
	C(int i,int j, int k):B1(i,j),B2(i,j),c(k)
	{
		cout << "c���캯��ִ��" << endl;
	}
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

	C c1(1, 2, 3);
	c1.static_number = 12;
	C::static_number = 30;
	/*���������͹��캯������˳��
	A���캯��ִ��
	B1���캯��ִ��
	A���캯��ִ��
	B2���캯��ִ��
	c���캯��ִ��
	C��������
	B2��������
	A��������
	B1��������
	A��������
	�밴���������. . .

	 * 
	 */
}

int main(void)
{
	playObject();
	system("pause");
	return 0;
}

/*
*(1)��̬��Ա���� ��̬��Ա���������࣬���������ڶ���
*
*(2)�����๹�캯������������
*	1.����һ�����������ͬʱ���첢��ʼ�����еĻ������
*	2.������Ĺ��캯����ʼ��ֻ��ʼ������ֱ�ӻ��ࡣÿ����Ĺ��캯���������ʼ������ֱ�ӻ��ࡣ
*		һ��һ�㴫����ȥ��
*	3.�����๹�캯����ʼ���б�ʵ��ֵ�ֱ𴫵ݸ�����ֱ�ӻ��ࡣ
*		����Ĺ���˳��͡������б��л���ĳ���˳�򱣳�һ�¡�
*	4.ÿ��������������������ͷ��Լ��������ڴ棬��������������ͷ����������ڴ档�����������������ͷŸ��������ڴ档
*	
*��ʽ��ʼ�����ࣺC(int i,int j, int k):B1(i,j),B2(i,j),c(k)
*��ʽ��ʼ�����ࣺ��һ���������һ�����������Ĺ��캯������ô��ʼ����ʱ����Բ����ָ��࣬
*	��ʽ��ʹ�ò��������Ĺ��캯������ʼ����
*
*	
*(3)
*
*
*/