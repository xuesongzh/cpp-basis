#include<iostream>
#include<cstdlib>
using namespace std;

int main004(void)
{
	/*
	 * c�������ж��嶼Ҫ���ļ�ͷ����c++������ʱ��Ҫ����ʱ����
	 */
	for (int i = 0; i < 10;i++)
	{
		cout << i << endl;	//i�����������������forѭ���ڲ�
	}


	//c++����ʹ��{}��ʼ������
	int aaa = 5;	//C���Զ����ʱ���ʼ��
	int bbb{ 6 };	//c++���Կ���ʹ��{}��ʼ������
	int ccc = { 7 };	//���Լ�=��Ҳ���Բ���=
	for (int i{ 0 }; i < 10;i++)
	{
		cout << i << endl;
	}

	//����ʹ��{}��ʼ��
	int arrayInt[]{11, 12, 34};	//c++����д��
	//int arrayInt[]={11, 12, 34};//c����д��
	for (int i{ 0 }; i < sizeof(arrayInt)/sizeof(arrayInt[0]);i++)
	{
		cout << arrayInt[i] << endl;
		cout << *(arrayInt + i) << endl;
	}

	int ddd = 3.5f;	//������һ�����棬ddd=3;--ϵͳִ������ʽ��������������ת��
	//int eee{ 3.5f };	//��ʾ��Ҫ����ת��������
	//ֱ��ʹ�õȺŸ�ֵ����c�����﷨������ת�����ᱨ������{}��c++�﷨��ת���ᱨ��
	
	
	system("pause");
	return 0;
}
/*
* (1)c++ʹ��{}��ʼ��������
*/