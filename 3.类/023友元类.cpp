
#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;

class A
{
private:
	int number;
public:
	//���캯��
	A(int number)
	{
		this->number = number;
	}
	friend class  B;	//���ﻹû�ж�����B������û��������еı���������������ǰ���һ�������� class B;
	
};

class B
{
private:
	int number02=0;
public:
	
	void myFunction01(const A&temA);
};



void B::myFunction01(const A&temA)
{
	cout << "���Է�����A��˽�г�Ա" << endl;
	cout << temA.number << endl;
	
}


int main(void)
{
	A a(12);
	B b;
	b.myFunction01(a);


	system("pause");
	return 0;

}
/*
*(1)��Ԫ��
*	����һ����B����A����Ԫ�ࣨ����A��������friend class B;����
*		����B�ĳ�Ա�������Է�����A�����г�Ա�����ͳ�Ա����
*
*	1.ÿ���඼��������Լ�����Ԫ��������Ԫ���������Լ������Ԫ��������Ԫ�������Լ���������
*	2.��Ԫ��ϵ���ܱ��̳�
*	3.��Ԫ��ϵ�ǵ���ġ���A����B����Ԫ�࣬������B����A����Ԫ��
*	4.��Ԫ��ϵû�д����ԡ�A-->B-->C
*	
*
*2019��11��20��16:52:37
* Sunrise�ڶ���������ѧ�ڶ���ѧ¥1121ʵ����

*/



