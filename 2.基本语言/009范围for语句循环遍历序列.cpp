#include<iostream>
#include<cstdlib>
using namespace std;

int main090(void)
{
	//��Χfor���--���ڱ���һ������
	int ArrayInt[]{11, 12, 13, 14, 15};
	for (auto x:ArrayInt)	//����ArrayInt�е�ÿ��Ԫ�أ����ο�����x��(������ʱ��)
	{
		cout << x << endl;
	}
	//����ֱ�Ӽ�һ������
	for (auto x : {21,22,23,24,25})
	{
		cout << x << endl;
	}
	//Ϊ�˽�Լ����ʱ�䣬����ʹ�����������ϵͳЧ��
	for (auto &x:ArrayInt)
	{
		cout << x << endl;
	}
	
	
	
	system("pause");
	return 0;
}
/*
* (1)shift+F9��ӿ��ټ���
*/