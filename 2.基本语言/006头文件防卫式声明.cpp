#include<iostream>
#include<cstdlib>
#include"Head.h"
#include"Head2.h"	//Ҫ�Ӻ�����ֹ�ظ���������

using namespace std;

int main006(void)
{
	//��Ϊhead2.h������head.h�����Ի�����ض�������
	//������������ #dendef #define

	
	cout << g_globalh1 << endl;
	cout << g_globalh2 << endl;


	
	system("pause");
	return 0;
}
/*
* (1)ʹ��#ifndef #define��#endif������ͷ�ļ�����ʽ���
*  Sunrise�ڶ���������ѧ�ڶ���ѧ¥1121ʵ����
2019��10��28��16:25:03
*/