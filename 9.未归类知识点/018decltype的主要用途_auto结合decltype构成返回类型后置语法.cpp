#include<iostream>
#include<cstdlib>
#include <vector>

using namespace std;

//�����﷨
auto func(int a,int b)->int
{
	return 0;
}

auto add(int i,int k)->decltype(i+k)
{
	return i + k;
}

int&myfunction01(int&i)
{
	return i;
}
double myfunction01(double&i)
{
	return i;
}

//����ģ��
template<typename T>
auto myFunTemplate(T&tv)->decltype(myfunction01(tv))//�������ͺ��ã�Ҫ����tv��������tv����������÷������ͺ��������÷�
{
	return myfunction01(tv);
}

int main(void)
{
	//2.3decltype����Ҫ��;_decltype(auto)�÷�
	int i = 12;
	double d = 23.34;
	cout << myFunTemplate(i) << endl;//12
	cout << myFunTemplate(d) << endl;//23.34

	
	system("pause");
	return 0;
}
/*
* (2)2.3decltype����Ҫ��;_auto���decltype���ɷ������ͺ����﷨
*auto����û���Զ������ƶϵ���˼��ֻ�Ƿ������ͺ����﷨����ɲ���
* 
*/