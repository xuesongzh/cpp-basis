
#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
class A;

//class C;	//��Ϊ�������õ���C�������������Ұ���������ĺ�����˦�������ʽ
class C
{
private:
	int number03;
public:
	void myFunctionC(int x, A&a);

public:
};

using namespace std;


class A
{
	friend class  B;	//���ﻹû�ж�����B������û��������еı���������������ǰ���һ�������� class B;

	friend void C::myFunctionC(int x, A& a);
private:
	int number;
public:
	//���캯��
	A(int number)
	{
		this->number = number;
	}
	
};

class B
{
private:
	int number02 = 0;
public:

	void myFunction01(const A&temA);
};





void C::myFunctionC(int x, A& a)
{
	a.number = x;
	cout << a.number << endl;
	
}



void B::myFunction01(const A&temA)
{
	cout << "���Է�����A��˽�г�Ա" << endl;
	cout << temA.number << endl;

}


int main(void)
{
	A a(12);
	C c;
	c.myFunctionC(1, a);


	system("pause");
	return 0;

}
/*
*(1)��Ԫ��Ա����--�е�ʱ����Ҫ�����е����г�Ա������ȥ������һ����ĳ�Ա�����ͳ�Ա��������ֻ��Ҫһ����Ա����ȥ����
*
*�ܽ᣺
*	(1)friend�������ض�����·�����ĳ�Ա���Ժͳ�Ա������
*	(2)�ƻ�����ķ�װ�ԣ���������Ŀɿ������ά���ԡ�
*	(3)Ҫ����������ʹ����Ԫ��������Ԫ�ࡣ
*
*
*2019��11��20��16:52:37
* Sunrise�ڶ���������ѧ�ڶ���ѧ¥1121ʵ����

*/



