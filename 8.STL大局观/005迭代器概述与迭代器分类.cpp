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

//(3)��֤��������������Ĵ��룺
//������Щ_display_category���������غ�����
void _display_category(random_access_iterator_tag mytag)
{
	cout << "random_access_iterator_tag" << endl;
}

void _display_category(bidirectional_iterator_tag mytag)
{
	cout << "bidirectional_iterator_tag" << endl;
}

void _display_category(forward_iterator_tag mytag)
{
	cout << "forward_iterator_tag" << endl;
}

void _display_category(output_iterator_tag mytag)
{
	cout << "output_iterator_tag" << endl;
}

void _display_category(input_iterator_tag mytag)
{
	cout << "input_iterator_tag" << endl;
}

template <typename T>
void display_category(T ite)
{   //T�����ͱ��������Ƶ�����
	cout << "---------------begin-------------------" << endl;

	//����������ͽ� ����������ȡ������������ȡT���������͵����ࣻ
	typename iterator_traits<T>::iterator_category cagy; //�൱�ڻ�ȡ���������ࣻ
	_display_category(cagy); //����������ѡһ�����ʺϵĲ���������_display_category
	cout << "typeid(ite).name() = " << typeid(ite).name() << endl; //������10�ڽ�rttiʱ

	cout << "---------------end-------------------" << endl;
};



int main(void)
{

	//(1)
	vector<int>iv = { 100,200,3300 };
	for (vector<int>::iterator iter=iv.begin();iter!=iv.end();iter++)
	{
		cout << *iter << endl;
	}

	//3
	display_category(array<int, 100>::iterator());  //���� ����()��������� һ����ʱ����
	display_category(vector<int>::iterator());
	display_category(list<int>::iterator());
	display_category(map<int, int>::iterator());
	display_category(set<int>::iterator());
	
	
	system("pause");
	return 0;
}

/*
*(1)������
*�ٷ�˵����������һ�����ɱ���stdl����ȫ�����߲���Ԫ�ء��Ķ�����Ϊ����ָ��Ķ���
*���������ڱ�ʾ�����е�ĳһ��λ�ã�����ʵ�ֺ�������أ������������������ṩ��
*Ҳ����˵��һ���������������涨��ѡ���������
*���ɣ��������ʺ�����������صģ��󶨣��ġ���ͬ���������ĵ������ǲ�ͬ�ġ�
*iter ָ�룬*iter������ָ���Ԫ��
*
*
*(2)�������ķ�������
*�������ݣ����������ƶ��ض���˫��͵��򣩺����������ܽ��еĲ�����
*��������Ϊ��ָ�룬����������ʾ�¶�λ�ã�����һ�����������������Ծ������ÿ�������Ӧһ��struct
*	1.����͵�����output iterator				--��ǰд��
*		struct output_iterator_atg
*		һ��һ����ǰ�ߣ������ܹ�ͨ���������������д��Ӧλ�õ�ֵ��  *iter=value  ǰ++��--��
*	2.�����͵�����								--��ǰ��ȡһ��
*		struct input_iterator_atg
*		һ��һ������ǰ��Ԫ�ض�ȡԪ�أ�����˳��һ��һ������Ԫ�ص�ֵ
*	3.ǰ������� forward iterator			--��ǰ��ȡ���̳���input iterator
*	4.˫�������bidierctional iterator		--˫���ȡ
*	5.������ʵ�����					--�����ȡ
*		random-access iterator
*	��Щ�ṹ���м̳й�ϵ�ģ�5-->4--->3--->2
*
*	������������е����������ǲ��������е��������е���������stack queue�Ͳ��ṩ��������
*(3)��֤��������������Ĵ���
*
*
*
*/