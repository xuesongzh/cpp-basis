#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include <memory>
#include <set>
#include <map>
#include <list>
#include <array>

using namespace std;

void *operator new(size_t size)
{
	return  malloc(size);
}



class A
{
public:
	A()
	{
		cout << "������A���޲ι��캯��" << endl;
	}
	A(int m):m_a(m)
	{
		cout << "�����в������캯��" << endl;
	}

	~A()
	{
		cout << "������A����������" << endl;
	}
	//��λnew����
	void *operator new(size_t size,void*pHead)
	{
		return  pHead;//�յ�ԭʼ��ַ�����ؼ���
	}

public:
	int m_a;

};

int main(void)
{
	//(1)
	void *myPlaceNew = (void*)new char[sizeof(A)];//�ڴ�����ȷ������
	A*myA = new (myPlaceNew)A();//�����޲ι��캯������myPlaceNew�������
	
	void *myPlaceNew02 = (void*)new char[sizeof(A)];
	A*myA02 = new (myPlaceNew02)A(2);//�����в������캯����myPlaceNew�������

	//��ô����
	myA->~A();//���캯���������ֶ����ã��������������ֶ�����
	myA02->~A();
	delete[](void*)myA;
	delete[](void*)myA02;


	system("pause");
	return 0;
}

/*
*(1)��λnew---placement new  ��ָ���Ŀռ乹�����
*	1.��new������û��delete
*	2.���ܣ����Ѿ������ԭʼ�ڴ��г�ʼ��һ������
*		1.�Ѿ������ڴ棬��λnew���������ڴ棬����Ҫ�����ǽ������λnew����Ҫʹ�õ��ڴ�������
*		2.��ʼ��һ������--��ʼ��һ��������ڴ�--���ö���Ĺ��캯����
*	˵���ˣ�������һ������õ��ڴ�ռ��е��ù��캯������һ������
*ʹ�ö�λnew�ﵽ���ù��캯����Ŀ��
*
*��ʽ��
*new(��ַ) �����ͣ�������
*
*
*�������غܶ�汾��operator new�����ǵ�һ�������ǹ̶��ģ�����size_t ��ʾ��Ҫnew�����sizeֵ��
*
*2019��11��29��21:46:26
* Sunrise�ڶ���������ѧ�ڶ���ѧ¥1121ʵ����

*/