#include<iostream>
#include<cstdlib>
using namespace std;

void functionSwap(int&num1,int&num2)	//ʹ����������������ֵ
{
	int temp;
	temp = num1;
	num1 = num2;
	num2 = temp;
}

int main007(void)
{
	int value = 10;
	int &refValue = value;	//value�ı�������refValue������&����ȥ��ַ���������Ҫʹ��c����ȥ����c++
	refValue = 20;
	cout << value << endl;
	//�������ò�������ռ�ÿռ䣬�������Ϊռ��ͬһ���ڴ棨ʵ�ʲ���ռ��ͬһ���ڴ棩
	//�������ñ����ʼ����Ҫ��Ȼ��˭���������

	//int &reference = 10;	//	���󣬱����ʼ��һ������
	//float &reference = value;	//�����������ͱ�����ͬ

	
	//���õ�����--ͨ�����ðѲ������ݵ������ڲ����ں����ڲ��Ϳ����޸��ڲ���ֵ

	int number1 = 11;
	int number2 = 22;
	functionSwap(number1, number2);
	cout << "number1=" << number1 << endl;
	cout << "number2=" << number2 << endl;

	system("pause");
	return 0;
}
/*
* (1)����
*	�������ΪΪ������������һ�����֣�һ��ʹ��&����ʾ�������֮��
*	�����ͱ������ֱ�ʾͬһ��������
*
*/