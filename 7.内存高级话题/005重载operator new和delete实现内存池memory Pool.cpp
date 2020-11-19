#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include <memory>
#include <set>
#include <map>
#include <list>
#include <array>
#include <ctime>

using namespace std;
class A
{
public:
	static  void *operator new(size_t size);
	static void operator delete(void *pHead);
	//�����ڴ������ͳ��,new�Ĵ���
	static int m_iCount;
	static int m_mallocCount;//malloc�Ĵ���
private:
	A*next;
	static A*m_FreePosi;//����ָ��һ����Է����ȥ���ڴ��׵�ַ
	static int m_sTrunkCount;//һ�η�����ٱ��ĸ�����ڴ�
	
};

//��̬�����Ķ���
int A::m_iCount = 0;
int A::m_mallocCount = 0;
A*A::m_FreePosi = nullptr;
int A::m_sTrunkCount = 5;//һ�η���5���ĸ����ڴ���Ϊ�ڴ���ӵĴ�С


void* A::operator new(size_t size)
{
	A*temLink;
	if (m_FreePosi==nullptr)
	{
		//Ϊ�գ�����һ����ڴ�
		size_t realSize = m_sTrunkCount*size;//����m_mallocCount�����ڴ�
		m_FreePosi = reinterpret_cast<A*>(new char[realSize]);
		temLink = m_FreePosi;
		//�ѷ����������һ���5С���ڴ�Ҫ�˴��������������Ժ�ʹ��
		for (;temLink!=&m_FreePosi[m_sTrunkCount-1];temLink++)
		{
			temLink->next = temLink + 1;
		}
		temLink->next = nullptr;
		++m_mallocCount;
	}

	temLink = m_FreePosi;
	//Ѱ����һ��newʹ�õ��ڴ��
	m_FreePosi = m_FreePosi->next;
	++m_iCount;
	return temLink;
}

void A::operator delete(void* pHead)
{
	(static_cast<A*>(pHead))->next = m_FreePosi;//��Ҫ�ͷ��ڴ�ռ���ڴ��ָ����һ�η�����ڴ�飬�������ڴ���������
	//��Ҫ�ͷ��ڴ��ָ��ָ����һ��Ҫ������ڴ档������һ��
	m_FreePosi = static_cast<A*>(pHead);
	//�����ڴ治�����������գ���û�й黹������ϵͳ�����ǹ�������ġ�
	
}



int main(void)
{
	clock_t start, end;
	start = clock();
	for (int i=0;i<50000000;i++)
	{
		A*p1 = new A();
		printf("�ڴ��ַΪ=%p\n", p1);
	}
	end = clock();
	cout << "����new�����ڴ�Ĵ���Ϊ" << A::m_iCount << endl;
	cout << "����malloc�ڴ�Ĵ���Ϊ" << A::m_mallocCount << endl;
	cout << "��ʱ��ms��=" << end - start << endl;

	system("pause");
	return 0;
}

/*
*(1)�ڴ��Ҫ���ʲô���⣿��
*	1.����malloc�Ĵ���(�����ڴ�Ĵ���)������malloc()���ô�������ζ�ż��ٶ��ڴ���˷�
*	2������malloc�ĵ��ô������ṩ���������Ч�ʣ���������Ч�ʲ�����
*�ڴ�ص�ʵ��ԭ��
*	1.ʹ��malloc����һ����ڴ棬����malloc�����ڴ�Ĵ���������Ҫ�ڴ��ʱ��һ��һ��ķ��������
*	2.������ڴ���ù��ʱ��������һ����ڴ水��С����������
*��ҪĿ�ģ������ڴ��˷ѣ��������Ч��
*
*(2)���һ�����ʵ����ʾ����
*���һ������ڴ�أ�ʹ��new��delete����ʵ��
*
*
*
*(3)
����new�����ڴ�Ĵ���Ϊ50000000
����malloc�ڴ�Ĵ���Ϊ10000000
��ʱ��ms��=6764
*
*
*/