#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;
template<typename T,typename U>
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

//�������з����汾�����ܴ����ػ��汾
//��T��U��Ϊint���ͣ�����ϣ����һ���ػ��汾--��������������int��ϵͳִ�����ǵ��ػ��汾����
//ȫ�ػ������е�����ģ�������T U���þ�������ʹ���
template<>//ȫ�ػ�������int����
class TC<int,int>
{//���淺���汾��T U�����ֱ��Ӧ�����int   int
	//������Զ��ػ��汾������
public:
	void FunctionTest01()
	{
		cout << "int int �ػ��汾�汾" << endl;
	}
	
};


template<>//ȫ�ػ�������double����
class TC<double,int>
{//���淺���汾��T U�����ֱ��Ӧ�����int   int
 //������Զ��ػ��汾������
public:
	void FunctionTest01()
	{
		cout << "double int �ػ��汾�汾" << endl;
	}

};



template<>//ȫ�ػ�
void TC<double,double>::FunctionTest01()
{
	cout << "double doubel FunctionTest01�ػ��汾�汾" << endl;
}


int main(void)
{
	//�ػ��汾���룬������������ѡ��
	TC<char, int>tchar;
	tchar.FunctionTest01();//���÷����汾

	TC<int, int>tint;
	tint.FunctionTest01();//����int,int �ػ��汾

	TC<double, int>tdouble;
	tdouble.FunctionTest01();//����double int�汾


	//�ػ���Ա��������������ģ��
	TC<double, double>tdooo;
	tdooo.FunctionTest01();//����ȫ�ػ��ĳ�Ա����

	system("pause");
	return 0;
}

/*
*(1)�ػ�---����
*����--�������ָ������
*�ػ�--�����������ģ�������������Դ�������д�ʺ�����ר�ô���
*	��ģ��ȫ�ػ�
*		1.����ȫ�ػ�
*		2.�ػ���Ա������������ģ��
*�ػ��汾��������ࡣ
*--------------------------------------------------------
*�����汾���캯��
�����汾
int int �ػ��汾�汾
double int �ػ��汾�汾
�����汾���캯��
double doubel FunctionTest01�ػ��汾�汾
�밴���������. . .
*
*(3)
*
*
*/