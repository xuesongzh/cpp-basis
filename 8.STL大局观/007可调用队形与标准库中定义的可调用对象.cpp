#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include <memory>
#include <set>
#include <map>
#include <list>
#include <array>
#include<functional>
using namespace std;

class A
{
public:
	bool operator()(int i,int j)
	{
		return i > j;
	}
	
};

int main(void)
{
	plus<int>();//��()����һ����ʱ���󣬾���һ���ɵ��ö���


	//(3)��׼���ж���ĺ���������
	vector<int>myVector = { 234,45,45,354,56,656,34,45645,654,7645,6,456,456 };
	A myA;
	sort(myVector.begin(), myVector.end(), myA);
	for (vector<int>::iterator iter=myVector.begin();iter!=myVector.end();iter++)
	{
		cout << *iter << endl;
	}

	//ʹ��ϵͳ����ĺ�������
	sort(myVector.begin(), myVector.end(), greater<int>());//()������ʱ����
	sort(myVector.begin(), myVector.end(), less<int>());//()������ʱ����
	for (vector<int>::iterator iter = myVector.begin(); iter != myVector.end(); iter++)
	{
		cout << *iter << endl;
	}
	

	system("pause");
	return 0;
}

/*
*(1)��������function object���º���functors��
*��STL�У���������һ���Ǻ��㷨����ʵ���ض��Ĺ��ܡ�Ҳ����˵����������Ҫ���ڷ����������
*�ɵ��ö���class A{public: void operator(){}}
*
*
*(2)��׼���ж���ĺ�������
*��׼����ҲΪ�����ṩ��������ֳ�����ʹ�õĺ�������ʹ������֮ǰ��Ҫ����һ��ͷ�ļ�functional
*���ࣺ
*	1.����������
*	2.��ϵ������
*	3.�߼�������
*	4.λ������
*	
*(3)��׼���ж���ĺ���������
*
*
*
*
*/