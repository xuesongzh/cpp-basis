#include<iostream>
#include<cstdlib>

using namespace std;

int main(void)
{
	int x = 5;
	auto f1=[=]()//�ڲ������һʱ�̣�x��ֵ�Ѿ����Ƶ�lambda������
	{
		return x;
	};
	x = 10;
	cout << f1() << endl;//5,����������Ϊ��10.
	//���ǰ�ֵ������ⲿ��������lambda���ʽ�����ʱ�̾ͱ���ֵһ�ݴ洢��lambda���ʽ�У������������lambda
	//���ʽ�ڲ���ֵ���������Ľ���취����ʹ��&����
	system("pause");
	return 0;
}
/*
* (1)lambda���ʽ�ӳٵ����׳���ϸ�ڷ���
* ������������lambda���ӳٵ���
* 
* (2)
* (3)
* (4)
* (5)
* (6)(7)
*/