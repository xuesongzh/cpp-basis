#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include"myArray.h"
using namespace std;

int myFunction(int a, int b)
{
	return  a + b;
}


//�Ѻ���ָ����Ϊ����һ�������Ĳ������ݣ���
//
//����һ������ָ������
typedef int(*FunType)(int, int);

template <typename T, typename F=FunType>//������ʱ��ָ������
void testFunction(const T&i, const T&j, F myfunc=myFunction)//��Ĭ�ϲ���
{
	cout << myfunc(i, j) << endl;
}

int main(void)
{
	//a
	myArray<> my_array01;//��ȫ��ģ�������Ĭ��ȱʡֵ
	myArray<int >my_array02;//�ڶ�������ʹ��Ĭ��ȱʡֵ


	//b.����ģ���Ĭ�ϲ��� testFunction��������Ĭ��ֵ
	testFunction(3, 4);
	
	system("pause");
	return 0;
}

/*
*(1)Ĭ��ģ�����
*	a.��ģ��--��ģ�����ֺ������ʹ��<>���ṩ�������Ϣ��<>��ʾ����һ��ģ��
*	b.����ģ���Ĭ�ϲ���
*		�ϱ�׼ֻ��Ϊ��ģ���ṩĬ��ģ�������c++11�±�׼����Ϊ����ģ���ṩĬ�ϲ���
*(2)
*
*(3)
*
*
*/