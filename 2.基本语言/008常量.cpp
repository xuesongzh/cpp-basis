#include<iostream>
#include<cstdlib>
using namespace std;

constexpr int functuonReturn()	//����һ��ֵ�ĺ���
{
	//�����������ı��������ʼ��
	return 5;
}


int main009(void)
{
	const int var = 7;	//	������������ʾ���������ֵ���Ҳ���ȥ�ı�
	//var = 8;	//	error���������
	//ʵ���Ͽ���ͨ���������ı�
	int&var2 = (int&)var;
	var2 = 100;
	cout << var << endl;	//=7
	cout << var2 << endl;	//=100

	cout << &var << endl;
	cout << &var2 << endl;	//��ַ��ͬ
	//�ܽ᣺�Ӷϵ����ʱ��var=var2=100,����coutֵ��ͬ������������ַ��ͬ
	////--ʵ���ϣ�����������ô�򵥡������������ֽ�


	//constexpr�ؼ���
	constexpr int var3 = 100;
	int& var4 = (int&)var3;
	var4 = 200;
	cout << var3 << endl;
	cout << var4 << endl;
	//������������ͬ�����ڴ��е�ֵ��ͬ������cout�е�ֵ��ͬ
	if (var3==var4)	//������ִ�������䡣
	{
		cout << "����������ͬ" << endl;
	}
	
	//constexpr int var5 = functuonReturn();	//������ԭ�ͱ������constexpr�ؼ�����ʵ��
	//ע�⣺va2013������ؼ��ֲ�֧�ֱ��룬����дӦ�ÿ��Ե��óɹ�
	//functuonReturn();	//��������ͨ����һ������
	system("pause");
	return 0;
}
/*
* (1)�������ǲ������
* const�ؼ��ֱ�ʾ�������˼
* 
*��2�� constexpr�ؼ���(vs2013��֧������ؼ���)
*	c++11������Ĺؼ��֣�Ҳ��һ�������ĸ���ڱ����ʱ����ְ���϶�����������
* 
*/