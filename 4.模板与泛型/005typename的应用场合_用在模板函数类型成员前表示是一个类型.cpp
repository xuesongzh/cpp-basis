#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

//���ַ����ĳ���
template<typename T>
typename T::size_type GetLength(const T&c)
{
	if (c.empty())
	{
		return 0;
	}
	return c.size();
}


int main(void)
{
	string mytest = "jisuanjizuchegnyuanli";
	string::size_type size = GetLength(mytest);//�ȼ����޷�������

	
	system("pause");
	return 0;
}

/*
*(1)typename��ʹ�ó���
*	1.��ģ�嶨�����档typename�������Ĳ��������Ͳ���		template<typename T,int a,int b>
*	template<typename T>		//����ΪT��ģ�����
*	typename ����ʹ��class�������class�����ඨ�壬��ʾ���Ͳ���
*	2.ʹ��������ͳ�Ա����typename����ʾ����һ������
*	::���Ա�ʾ���Ա������
*	::�����Ա�ʾ����ģ��������ͳ�Ա��
*				��������ֵ
*		typename myVector<T>::myIterator   myVector<T>::myend()
*		typename ���ô�������ʽ���߱�����myVector<T>::myIterator��һ������
*
		typename T::size_type GetLength(const T&c)
		�е�T::size_typeҲ�����ͣ�����ǰ����Ҫ����typename
*
*(2)
*
*(3)
*
*
*/