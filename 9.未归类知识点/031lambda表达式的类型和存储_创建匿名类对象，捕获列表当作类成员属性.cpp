#include<iostream>
#include<cstdlib>
#include<functional>


using namespace std;

int main(void)
{
	auto f1 = [] {};//f1���൱��һ��δ�������� ���Ͷ���

	int x = 5;
	auto f2 = [=]()
	{
		return x;
	};//f2Ҫ����һ�������ͱ�������Щ������ⲿ����Ҫ�����ڲ���Ϊ��Ա�������ڡ�

	//lambda��function���ʹ������
	std::function<int(int)>f3 = [](int value)->int
	{
		value++;
		return value;
	};
	cout << f3(15) << endl;//16

	std::function<int(int)>f4 = std::bind(
		[](int value)
	{
		return value + 1;
		
	},placeholders::_1
	);
	//bind��һ�������ǿɵ��ö�����ߺ���ָ�룬�ڶ��������Ǻ�������
	cout << f4(23) << endl;//24

	//�����б�Ϊ�յ�lambda���ʽ������ת����һ����ͨ�ĺ���ָ�롣
	using funcpType = int(*)(int);//����һ������ָ������
	funcpType fp = [](int value) {return value + 1; };
	cout << fp(123) << endl;//124
	
	system("pause");
	return 0;
}
/*
* (1)lambda���ʽ�����ͺʹ洢
* c++11��lambda���ʽ�����ͱ���Ϊ���հ����ͣ�closure type������
* �հ�--�����ڲ��ĺ������ɵ��ö��󣩣������Ͼ���lambda���ʽ����������ʱ�ڵĶ���
* lambda���ʽ��һ�ֱȽ�����ģ������ģ��� ���ͣ��հ��ࣩ�Ķ���
* ����Ҳ������Ϊ����һ������operator()���͵Ķ���Ҳ���Ƿº�������������
*
* �������ǿ���ʹ��std::function  std::bind������͵���lambda���ʽ��ÿ��lambda����
* ��������������һ����һ�޶��������͡�
* 
* lambda���ʽ�����﷨���ǿ��Ծ͵ض��������������͵ط�װ��С�Ĺ��ܱհ���
* 
* (2)�﷨�ǵĸ���
*	����һ�ֱ��д��
*	int a[4];
*	a[0]=5;//�������ڲ���д��*(a+0)=5;
*	�﷨�ǵ�Ŀ�ľ���������д�Ĵ�����Ӽ򵥣�������⣬���ٴ������Ļ��ʡ�
*	�﷨���ǻ����������е����ԣ�������һ��������ʹ���������򵥣�����û���������Ե�ԭ�й��ܡ�
*	lambda���ʽ���Կ��ƶ���º����հ��������к��������﷨�ǡ�
* (3)
* (4)
* (5)
* (6)(7)
*/