#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include"myArray.h"
using namespace std;


int main(void)
{

	myArray<int, 100>my_array01;
	myArray<int>my_array02;//ʹ��һ��Ĭ�ϲ���

	my_array02.myFunction01();
	
	system("pause");
	return 0;
}

/*
*(1)������ģ�����
*	1.һ�㸡���Ͳ���������ģ����� float doubleһ�㲻������
*	2.������һ��Ҳ��������������ģ�������
*
*(2)
*
*(3)
*
*
*/