#include<iostream>
#include<cstdlib>

using namespace std;

int main(void)
{
	int x = 10;
	auto f1 = [=]()mutable //����mutable���Ը���x��ֵ����Ȼ�ǰ�ֵ�����x
	{
		x = 234;
	};
	
	
	system("pause");
	return 0;
}
/*
* (1)ambda���ʽ�е�mutable
* mutable���׸ı�ģ��ױ��
* �����ǲ���һ��const���Եı���������mutable�Ϳ����޸�����ֵ��
* (2)
* (3)
* (4)
* (5)
* (6)(7)
*/