#include<iostream>
#include<cstdlib>
using namespace std;

struct Student
{
//private:
	int number;
	char name[128];
	void functionInc()	//���ڲ����ܷ��ʳ�Ա����
	{
		number++;
		return;
	}
};


int main013(void)
{
	//����private���Ͳ���ʹ�����ַ�������Ϊ�����ڽṹ���������˽�����Ի���˽�з���
	Student student1 = { 1000, "baiqianlong" };
	
	system("pause");
	return 0;
}

/*
* (1)��Ķ�����Ȩ�����η�
*	a.public ���е�
*		��������˼����������η����νṹ/���еĳ�Ա�����ͳ�Ա�������Ա������ʡ�
*		һ��������Ҫ�ܹ����ⲿ���ʵ����Ի��߱���������Ϊpublic,�ͺ��������ⲿ�ӿ�һ����
*	b.private ˽�е�
*		��������η��������еĳ�Ա���Ի��߳�Ա������ֻ�����е����Ի��߷������ʡ�
*	c.protected �������ͣ���ڿβ�����--�ڼ̳��н��⣩
*	���ۣ�struct�ṹ��Ĭ������public���͵ģ���д�������η�������public���͵ġ�
*	 Sunrise�ڶ���������ѧ�ڶ���ѧ¥1121ʵ���� 2019��11��2��12:40:05
*/