#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include <map>

using namespace std;
//���庯��ģ��
template<typename T1,typename T2,typename T3>
T1 Sum(T1 i,T3 j)
{
	T1 result = i + j;
	return result;
}

int main(void)
{
	//(1)
	auto result = Sum<int, int, int>(2000000000, 2000000000);
	auto restult02 = Sum<double, int, int>(2000000000, 2000000000);

	cout << result << endl;//-294967296
	cout << restult02 << endl; //4e+09


	system("pause");
	return 0;
}

/*
*(1)��ʽָ����ģ�����
*���Ƶ���ģ�����ϵͳ���Զ��ƶϣ�������ʽָ��ģ�����ϵͳ������ʽָ�������ȡ���
*һ�㽨�飺ģ�庯��������ָ���������Ͷ�ָ����������

*2019��11��25��10:49:52
* Sunrise�ڶ���������ѧ�ڶ���ѧ¥1121ʵ����

*
*/