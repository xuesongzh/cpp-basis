#include<iostream>
#include<cstdlib>
using namespace std;

void myFunction()
{
	
}

void myFunction02()	//(1)
{
	return myFunction();	//���ֿ���
	//return;	//	Ҳ����
	
}


int* myFunction03()	//����2--����ָ��
{
	int temValue = 9;
	return &temValue;	//���д������û�����⣬���Ǵ��ھ޴��������뿴����
	//��һ������ȡ��ַ��������ʱ�����ĵ�ַ������ִ����Ϻ󣬱����ڴ汻ϵͳ���գ�
}

int& myFunction04()	//����2--��������--���ﷵ�ص��Ǿֲ����������ã���������ڴ汻���գ�����������
{
	int temValue = 9;
	cout << "�Ӻ�����temValue�ĵ�ַ" << &temValue << endl;
	return temValue;
}


int myFuction05(void)	//(3)û���βεĺ�����
{
	return 1;
}



int myFunction06(int a, int b);	//(4)��������
int myFunction07(int a, int b);


//��6��������������ʽ����--��ӷ��ض��ֵ
struct Student
{
	int number;
	int age;
	string str;
};

void myFunction08(Student&stu)	//(06)���ã����޸��ⲿ��ֵ
{
	stu.number = 10000;
}

//��07����������
void myFunction09(int i)
{
	
}
void myFunction09(float i)
{
	
}
void myFunction09(int i,int j)
{

}
void myFunction09(int i, float j)
{

}
void myFunction09(float i, int j)
{

}




int main(void)
{

	int *p = myFunction03();
	*p = 1000;
	cout << *p << endl;	//	������ڴ�ռ���д�����ݣ����ھ޴�ȫ����

	//�������ú�������
	int&k = myFunction04();		//�������⣬�ֲ������Ѿ����ͷţ����ò�����
	cout << "main������temValue�ĵ�ַ" << &k << endl;
	/*
	 * �Ӻ�����temValue�ĵ�ַ002EF7E0
	 * main������temValue�ĵ�ַ002EF7E0
	 *
	 * ��ͬһ���ڴ�
	 */

	//�����Ƿ����ʹ�����α���������  ---����д��ok
	int m = myFunction04();
	cout << "main�����еĵ�ַ" << &m << endl;
	/*
	 * main�����еĵ�ַ003EFC58
	 * ����ͬһ���ڴ�ռ��ǰ�ȫ�ġ�
	 */



	//��6��
	Student student1 = { 123,14,"baiqianlonga" };
	myFunction08(student1);
	cout << student1.number << endl;	//10000���޸�֮���ֵ

	
	
	system("pause");
	return 0;
}

/*
* (1)������������void��ʾ�����������κ����͡��������ǿ��Ե���һ������������void�ĺ�����
*	������Ϊ��һ������������void���ͺ����ķ���ֵ��
*
*(2)��������ָ��ͷ������õ����
*	ע��ֲ������ں���ִ����ϻ��ͷţ����۷���ָ�����ͻ����������Ͷ��ǲ���ȫ�ġ�
*	�е�ʱ�����ǴӺ����з�������ʱ��ϵͳ����ʱ����һЩ��������һЩ���ǲ�֪���Ĵ�������������������һЩֵ������ת���ȣ�
*
*��3�������βεĺ�������д��
*	���Ա����β��б�Ϊ�գ�����(void)
*
*��4�����һ���������ǲ����õĻ�����ú�������ֻ���������֣�û�ж��岿�֡�--�����ں�����ԭ�������
*
*��5������������.cpp�У�������.h�С�����ֻ�ܶ���һ�Σ���������������Ρ�
*
*(6)�����������β�--���ʵ�ֺ������ض��ֵ��
*	ֵ���������ݵĽṹ�ܴ��ʱ�򣬻�ķѺܶ��ڴ棬�紫��һ��student�ṹ��,������ֵ��������
*	��c++�У�ϰ��ʹ�����õ���ʽ������Ҫϰ�����������͵��β�������ָ�����͵��βΡ��ᳫʹ���������͵��βΡ�
*
*(7)��������--�������ͣ�������˳��ͬ���ṹ�ɺ�������
*
*	
*	2019��11��12��21:21:29
*	 Sunrise�ڶ���������ѧ�ڶ���ѧ¥1121ʵ����

*	
*/