#include<iostream>
#include<cstdlib>
using namespace std;

struct Student
{
	//��Ա����
	int number;	//ѧ��
	char name[100];	//ѧ����
};

void functionStruct(Student temstu)	//	�β��ýṹ�����
{
	temstu.number = 1002;
	strcpy_s(temstu.name, sizeof(temstu.name), "lisi");
	return;
}



void functionStruct02(Student &temstu)	//	�β��ýṹ������
{
	temstu.number = 1002;
	strcpy_s(temstu.name, sizeof(temstu.name), "lisi");
	return;
}

void functionStruct03(Student *ptemstu)	//	��ָ��ṹ�������ָ������������
{
	ptemstu->number = 1002;
	strcpy_s(ptemstu->name, sizeof(ptemstu->name), "lisi");
	return;
}

//�����ĳ�Ա�������԰�����Ա����������
struct  Teacher
{
	int number;
	char name[128];

	//��Ա���ԣ�Ҳ�з���
	//void functionInc(int number)
	void functionInc()	//	���ó�Ա��������Ҫд����

	{
		number++;
		return;
	}
};


int main012(void)
{
	//�ṹ���Զ������������--����ṹ�����
	Student student1;	//����ṹ��������c++�п���ʡ��struct��ֱ��ʹ�ýṹ������
	student1.number = 10001;
	//student1.name = "baiqianlong";	//����ֱ�Ӱ��ַ�����ֵ���ַ���������
	strcpy_s(student1.name, sizeof(student1.name), "baqianlong");
	cout << student1.name << endl;	//baiqianlong 
	cout << student1.number << endl;	//10001

	//���ú������鿴�ܷ�ı�ṹ�������ֵ--�ѽṹ��������ݸ�����
	functionStruct(student1);//Ч�ʵͣ����ݴ�ʵ�δ��ݸ���ʽ�������������ڴ�ռ�����ݿ���

	//ֵû�иı�
	cout << student1.name << endl;	//baiqianlong 
	cout << student1.number << endl;	//10001


	
	functionStruct02(student1);	//	ʹ�����ã���ͬһ���ڴ�ռ� shift+f9���ټ���
	/*
	 * &student1	0x003afe04 {number=10001 name=0x003afe08 "baqianlong" }	Student *
	   &temstu	    0x003afe04 {number=1002 name=0x003afe08 "lisi" }		Student *
	 */


	functionStruct03(&student1);	//ʹ�ýṹ�������ָ������������

	cout << student1.name << endl;	//ֵ�ı�Ϊ���ú�����ֵ
	cout << student1.number << endl;	


	//c++�Խṹ�������--������Ա����
	struct Teacher teacher1;
	teacher1.number = 1000;
	strcpy_s(teacher1.name, sizeof(teacher1.name), "baiqianlong");
	teacher1.functionInc();	//	�ṹ������.��Ա������
	
	cout << teacher1.number;	//1001


	
	system("pause");
	return 0;
}

/*
* (1)�ṹ�ع�
*	a.--ֱ��ʹ�ýṹ���������������
*	b.--����������������
*	c.--��ָ��ṹ���ָ������������
*	�鿴ʵ�κ��βεĵ�ַ�����Կ�����ֵ����
&student1	0x002ffcc4 {number=10001 name=0x002ffcc8 "baqianlong" }	Student *
&temstu		0x002ffb8c {number=1002 name=0x002ffb90 "baqianlong" }	Student *
*	���ݴ�ʵ�ʲ������ݸ���ʽ����������ֵ��������
*
*��2��c++�еĽṹ��c�еĽṹ��ʲô��ͬ
*	c++�еĽṹ���˾���c���Ե����й��ܣ��������˺ܶ���չ���ܣ�����֮һ����c++�еĽṹ��������
*	��Ա���������ҿ��Զ����Ա������������--����Ϊ����������ĸ���
*	
*/