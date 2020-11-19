#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

template<typename T>
class TC
{
public:
	void FunctionTest()
	{
		cout << "���÷����汾����" << endl;
	}
};

//��Χ�ػ��汾  const
template<typename T>
class TC<const T>
{
public:
	void FunctionTest()
	{
		cout << "Const T�ػ��汾" << endl;
	}
};

//��Χ�ػ��汾  T*
template<typename T>
class TC<const T*>
{
public:
	void FunctionTest()
	{
		cout << "T*�ػ��汾" << endl;
	}
};


//��Χ�ػ��汾--��ֵ����
template<typename T>
class TC<const T&>
{
public:
	void FunctionTest()
	{
		cout << "T&�ػ��汾" << endl;
	}
};

//��Χ�ػ��汾--��ֵ����
template<typename T>
class TC<const T&&>
{
public:
	void FunctionTest()
	{
		cout << "T&&�ػ��汾" << endl;
	}
};

int main(void)
{
	TC<double>td;
	td.FunctionTest();//���÷����汾

	TC<double*>tdp;
	tdp.FunctionTest();//���÷����汾

	TC<const double> tcc;
	tcc.FunctionTest();//����const�ػ��汾
	
	TC<int&>ti;
	ti.FunctionTest();//���÷����汾


	TC<int&&>tii;
	tii.FunctionTest();//���÷����汾
	
	system("pause");
	return 0;
}

/*
*(1)
*ģ�������Χ��  int --�ػ�һ��const int  ��--С
*		��T��СΪT*
*		��T��СΪT& T&&
*		���ֶ��Ƿ�Χ��С
*(2)�ֲ��ػ����ػ���ϻ��Ǹ���ģ�壬��Ϊ����������Ͳ���T��
*ȫ�ػ���Ϻ����治�������Ͳ���T
* Sunrise�ڶ���������ѧ�ڶ���ѧ¥1121ʵ����
* 2019��11��25��15:50:32
*
*(3)
*
*
*/
