#include<iostream>
#include<cstdlib>
#include <vector>

using namespace std;

template<typename T>
T& DoubleMyself(T&value)
{
	value *= 2;
	return value;
}


template<typename T>
decltype(auto) DoubleMyself02(T&value)//ʹ��auto�ƶϷ���ֵ���
{//��auto����Ҫ�Ƶ������ͣ��Ƶ��������Ϊ���ǲ���decltype�Ƶ�
	value *= 2;
	return value;
}

int main(void)
{
	//2.4 decltype����Ҫ��;_decltype(auto)�÷�
	//1.���ں�����������
	int number01 = 100;
	DoubleMyself(number01) = 20;//���ص�����ֵ���ã����Կ��Ը�ֵ
	cout << "number01=" << number01 << endl;//20
	//ʹ��auto�ƶϷ���ֵ���,DoubleMyself02�ķ���ֵ�����int����һ����ֵ�����ܸ���ֵ��ֵ������decltype ok
	DoubleMyself02(number01) = 43;
	cout << number01 << endl;//43

	decltype(DoubleMyself02(number01))number02 = number01;
	cout << "number02=" << number02 << endl;//43
	
	system("pause");
	return 0;
}
/*
*2.4 decltype����Ҫ��;_decltype(auto)�÷�
*c++14�д��������﷨��������Ҫ֧��c++14�﷨
*	1.���ں�����������
* (3)
* (4)
* (5)
* (6)(7)
*/