#include<iostream>
#include<cstdlib>
using namespace std;

struct Student
{
	int number;
	int age;
	string name;
};

void ModifyStudent(Student&stu)
{
	stu.number = 100000;
}

//�βμ���const
void ModifyStudent02(const Student&stu)	//ѧϰ�����β��м�const��д�������������޸�����������ֵ
{
	//stu.number = 100000;	//�����޸�
	
}


void myFunction(const int&a)
{
	return;
}



int main(void)
{

	Student student1 = { 343,12,"baiqianlong" };
	ModifyStudent(student1);
	cout << student1.number << endl;	//	���޸ĺ��ֵ


	//��2��ʵ�����Ϳ��Ը������--����1
	const Student&student2 = student1;
	//student2��const���ͣ�student2������ΪModifyStudent�����Ĳ��������ǿ�����ΪModifyStudent02()��������
	ModifyStudent02(student2);
	//ModifyStudent(student2);

	//��2��ʵ�����Ϳ��Ը������--����2
	int aaa = 10;
	myFunction(aaa);
	myFunction(123);	//��������������const
	
	system("pause");
	return 0;
}

/*
* (1)�����β��д�cosnt����ʾ��������ֵ�����޸��������е�ֵ
* �ŵ㣺
*	��1�����Է�ֹ�������޸���ʽ��������ʵ�ε�ֵ���޸�
*	��2��ʵ�����Ϳ��Ը������,����ʹ��const������ͨ��������������
*/