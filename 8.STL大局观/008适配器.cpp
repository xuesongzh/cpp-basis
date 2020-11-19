#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include <memory>
#include <set>
#include <map>
#include <list>
#include <array>
#include <functional>

using namespace std;

class A
{
public:
	bool operator()(int value)
	{
		return 40 < value;
	}
};

int main(void)
{
	//*�㷨������bind
	vector<int>myVector = { 23,34,45,5,4,5453,34354 };
	//ͳ��ĳ��ֵ���ֵĴ���
	int count01 = count(myVector.begin(), myVector.end(), 34);
	cout << count01 << endl;//1

	//ͳ��ֵ����40��Ԫ�أ�ʹ��count_if
	A a;
	count01 = count_if(myVector.begin(), myVector.end(), a);
	cout << count01 << endl;//3
	//���ʹ��less�еĴ�������������ʵ�����ǵĹ���--ʹ��bind�������е�һ��������Ϊ40
	bind(less<int>(), 40, placeholders::_1);
	/*less<int>��operator()��һ��������Ϊ40����������������ɵ��ö���ʱ�򣬵ڶ�����������
	 *����placeholders::_1��ʾ���ڵ����������ʱ�򣬱�����ĵ�һ��������ȡ��
	 * 
	 */
	int count02 = count_if(myVector.begin(), myVector.end(), bind(less<int>()/*��ʱ����*/, 40, placeholders::_1));// placeholders::_1��һ��ռλ��
	cout << count02 << endl;


	
	//����
	//auto bf = bind(less<int>(), 40, placeholders::_1);
	//bf(19);//19���ݸ�placeholders::_1


	//����������
	cout << "RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR" << endl;
	for (vector<int>::reverse_iterator riter=myVector.rbegin();riter!=myVector.rend();riter++)
	{
		cout << *riter << endl;
	}

	
	system("pause");
	return 0;
}

/*
*(1)�������Ļ�������
*��һ�����еĶ����������ʵ��ĸ��죬�������Ӷ��������߼��ٶ���������һ����������
*Adapter(������) ͨ������ģ�͵Ĺ���������������һ��ģ�͵Ĺ��ܣ��൱�ڸı��˽ӿڣ���ʵ�ֲ��䡣
*
*(2)����������
*����������
*	2.1��ѧϰ��stack��deque�����Ʋ��ֹ�����ʵ�ֵġ�
*		queueҲ��deque����������
*�㷨������
*	����͵ľ��ǰ���binder
*	�ϰ汾�е�bind1st bind2nd��c++11���޸�Ϊbind��
*	����������վ��
*	https://en.cppreference.com/w/
*	https://www.cplusplus.com/
*	
*������������
*	����������
*(3)�ܽ�
*
*
*
*/