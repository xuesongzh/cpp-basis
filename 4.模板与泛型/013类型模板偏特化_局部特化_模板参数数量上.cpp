#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

template<typename T, typename U,typename W>
class TC//������tc��ģ��
{
public:
	void FunctionTest01()
	{
		cout << "�����汾" << endl;
	}
	//���캯��
	TC()
	{
		cout << "�����汾���캯��" << endl;
	}
};

//ģ���������--ƫ�ػ���2�������ػ�
template< typename U>//T W�󶨵����������
class  TC<int,U,int>
{
public:
	void FunctionTest01()
	{
		cout << "����--ƫ�ػ��汾���汾" << endl;
	}
};




int main(void)
{
	
	TC<double, double, double> tcddd;
	tcddd.FunctionTest01();//���÷����汾
	TC<int, double, int >tcidi;
	tcidi.FunctionTest01();//��������--ƫ�ػ��汾


	
	system("pause");
	return 0;
}

/*
*(1)����ģ��ƫ�ػ�--Ҳ�оֲ��ػ�
*	1.ģ�����������
*
*(3)
*
*
*/