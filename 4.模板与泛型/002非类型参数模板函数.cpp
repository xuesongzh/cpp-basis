#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

template <typename T,int S>//typename��ʾT��һ�����ͣ�T��һ�����Ͳ�����
T FunctionTemplate(T a)
{
	T tem = a + S;
	return tem;
}


//�������ܲ���
template<unsigned a, unsigned b>
int FunctionTemplate02()
{
	return a + b;
}

//�����Ͳ���--�Ƚ��ַ������ͬ
template<int L1, int L2>
int CharCompare(const char(&p1)[L1], const char(&p2)[L2])
{
	return strcmp(p1, p2);
}

int main(void)
{

	int Sum01 = FunctionTemplate02<23, 23>();//��ʽָ��ģ���������<>ָ���������Ϣ��
	int a = 12;
	//int Sum02 = FunctionTemplate02<a, 32>();//error�������ó���������ʱ���Ҫȷ��

	int Sum03 = FunctionTemplate<int, 12/*ָ��int S=12��T��������int*/>(13);//25--��ʽָ��ģ�������int����Ϊ12
	int Sum04 = FunctionTemplate<double, 13>(28);//ϵͳ��<>�ڴ��ݵĲ���Ϊ׼ 28.00000000
	cout << Sum04 << endl;

	//ģ�庯��CharCompare
	int result01 = CharCompare("jisuanji", "jisuanjizu");//û���ṩ������ģ��������Լ��ƶϳ���L1,L2
	//ϵͳʵ����Ϊint CharCompare(const char(&p1)[9], const char(&p2)[11])
	int result02 = CharCompare<9, 11>("jisuanji", "jisuanjizu");//��ʽָ��������ģ�����
	
	
	system("pause");
	return 0;
}

/*
*(1)ģ������б�
*	1.��ģ������б����滹���Զ�������Ͳ�����
*	2.�����Ͳ�����ʾ����һ����ֵ������ʹ��typename���Ρ�
*	3.������Ҫʹ����ǰѧϰ�Ĵ�ͳ��������ָ�������Ͳ�������������Ͳ���S�Ǹ����Σ�����ʹ��int S
*	T FunctionTemplate(T a,int S)
*
*(2)Ϊʲô��Ҫ�����Ͳ�����
*	��ģ�屻ʵ������ʱ�����ַ�����ģ�������ֵ���������û��ṩ�ģ������Ǳ������ƶϵģ����п��ܡ�
*		������Щֵ�����ǳ������ʽ����Ϊʵ������Щģ�嶼���ڱ����ʱ��ȷ���ġ�
*
*(3)ģ�嶨�岢�������ɴ��룬ֻ�������ǵ��ú���ģ��ʱ�򣬱�����Ϊ����ʵ����һ���ض��İ汾������Ż����ɴ��롣
*	���������ɴ����ʱ����Ҫ�ҵ������ĺ����塣���Ժ���ģ��Ķ���ͨ��������.h�С�
*
*
*/