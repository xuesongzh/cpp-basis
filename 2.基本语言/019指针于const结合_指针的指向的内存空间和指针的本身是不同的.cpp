#include<iostream>
#include<cstdlib>
using namespace std;



int main(void)
{
	const int abc = 12;
	//abc = 123;	//����

	char str[] = "I love China";	//�ո�Ҳռ��һ���ַ�
	char*p = str;	//����ָ��ָ���ַ�����ͷλ��
	*p = 'Y';	//	�����޸�
	p++;
	cout << str << endl;

	
	const char*p2 = str;	//p2ָ����ڴ�ռ䲻���޸�
	p2++;	//	����
	//*p2 = 'Y';	//error

	//�ȼ���const char*p2
	char const*p3 = str;
	//*p3 = 'Y';
	p3++;


	char*const p4 = str;	//����ʱ������ʼ����ָ���ָ�򲻿��Ըı䣬����ָ��ָ����ڴ�ռ���Ըı�
	*p4 = 'Y';
	//p4++;	//	����ָ���ָ���ܸı�
	
	const char*const p5 = str;	//ָ���ָ���ָ��ָ����ڴ�ռ䶼���ܸı�


	int i = 100;
	const int&a = i;	//	i�����ݲ���ͨ��a���޸ġ�����const��ʾa���г������ԣ�����i��������޸�


	//int &b = 12;	//	����
	const int &b = 12;	//��ȷ
	cout << b << endl;	//12--����ϵͳ���˹�����ϵͳ�Ƿ������ڴ��

	
	system("pause");
	return 0;
}

/*
* (1)const char*     char const *     char*const������
* 
*/