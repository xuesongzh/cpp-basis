
#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

class TypeConversion	//���ܣ���һ������ת��Ϊ0-100�洢����
{
public:
	//����һ������ָ�����ͣ���������һ�������βΣ�û�з�������
	typedef void(*myFunction)(int);
	//�ȼ���
	//using myFunction = void(*)(int);
public:
	static void myfunc(int value)	//��̬��Ա����
	{
		int test;
		test = 11;
	}
	//�µ�����ת�������������������ת��Ϊһ������ָ������
	operator myFunction()
	{
		//����Ҫ����һ������ָ
		return myfunc;//�������֣�������ַ�����ؼ���
	}

public:
	//����ת�����캯��--��һ��int��������ת��ΪTypeConversion����
	//explicit TypeConversion(int x = 0) :number01(x)
	TypeConversion(int x = 0) :number01(x)
	{
		if (x <= 0 && x>100)
		{
			x = 0;
		}
		else
		{
			number01 = x;
		}
	}
	
	//����ת�������--��--->>>>>>>������������
	//explicit operator int()const
	operator int()const
	{
		return number01;
	}
	//�����ת��Ϊdouble����
	operator double()const
	{
		return 1.0*number01;
	}
public:
	int Add()
	{
		number01 += 1;
	}
public:
	int number01;
};


int main(void)
{
	TypeConversion tc = 12;//��ʽ����ת����������ת��Ϊ����󣬵�������ת�����캯��������explict��ֹ��ʽ����ת��
						   //��12��ʽ����ת��Ϊһ����ʱ����Ȼ�󹹽���tc������ڴ�ռ��С�

	TypeConversion tc02(22);//��������ת�����캯��������û����ʽ����ת��

	TypeConversion tc03(1.00);
	//int m = tc03 + 4;//������--��֪��ת��Ϊint���ͻ���doble����


	system("pause");
	return 0;
}

/*
*
*(1)����ת���Ķ�����
*������--����
*������--����ָ������
*�����ԣ������ֻ��߶��ַ��������±�������֪����ô�������Ա�����ֻ�ܱ��档
* Sunrise�ڶ���������ѧ�ڶ���ѧ¥1121ʵ����
* 2019��11��23��21:34:57
*
*/