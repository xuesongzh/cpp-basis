#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include <list>

using namespace std;
//����ģ������
//template<typename T,typename U>//t u��ģ������������������ģ�������ǰ����typename��
template<
	typename T,//����ģ�����
	template<class>class Container	//����һ��ģ��ģ�����---��ô�����һ�У���
	//����һ�ֵȿ�д��
	//template<typename W>typename Container02//W�����ô�����ռλ���õ�
	
>
class  myClass
{
public:
	T m_i;
	Container<T>myc;	//container��Ϊһ����ģ����ʹ�ã�������vector<int>myc;��������һ����ģ��
	//Ҫ���ף�Ҫ��Container����һ����ģ����ʹ�ã��ͱ���Ϊ��ģ��ģ�������

	//���캯��
	myClass()
	{
		for (int i=0;i<10;i++)
		{
			myc.push_back(i);
		}
	}
};

//�����׶���һ������
template<typename T>
using myVec = vector<T, allocator<T>>;//�ֹ�ָ��������

template<typename T>
using myList = list<T, allocator<T>>;//�ֹ�ָ��������


int main(void)
{

	myClass<int, myVec>myvectorobj;//������������������Ԫ�أ�Ԫ��Ϊint
	//vector����һ��������Ԫ��,�ڶ��������Ƿ�����allocator

	
	system("pause");
	return 0;
}

/*
*(1)ģ��ģ�����
*����ģ������
*����ģ�����
*ģ��ģ������������Ǹ�ģ����������ģ������������Ǹ�ģ�塣
*(2)
*
*(3)
*
*
*/