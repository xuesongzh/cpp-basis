#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include <memory>
#include <array>
using namespace std;


int main(void)
{
	//����5��Ԫ�ص�����
	array<string, 5>mystring = { "fsdfd","fsfds","ds","dsf","dfd" };
	cout << mystring.size() << endl;//5
	mystring[0] = "fsdffffsdfsdfsdfsdfsfsfdf";
	cout << sizeof(string) << endl;//�ַ������͵Ĵ�С---28
	for (size_t i=0;i<mystring.size();i++)
	{
		cout << "------------------------------1" << endl;
		const char*p = mystring[i].c_str();
		cout << "Ԫ������Ϊ:" << p << endl;
		printf("�����ַΪ=%p", &mystring[i]);
		cout << endl;
		printf("ָ����ַ�����ַ=%p", p);
		cout << endl;
		cout << "------------------------------2" << endl;

	}
	
	/*
			 ------------------------------1
			Ԫ������Ϊ:fsdffffsdfsdfsdfsdfsfsfdf
			�����ַΪ=002EFB60
			ָ����ַ�����ַ=0063DA38
			------------------------------2
			------------------------------1
			Ԫ������Ϊ:fsfds
			�����ַΪ=002EFB7C
			ָ����ַ�����ַ=002EFB80
			------------------------------2
			------------------------------1
			Ԫ������Ϊ:ds
			�����ַΪ=002EFB98
			ָ����ַ�����ַ=002EFB9C		//string �Ƚ϶̣�ֱ���ں���洢
			------------------------------2
			------------------------------1
			Ԫ������Ϊ:dsf
			�����ַΪ=002EFBB4
			ָ����ַ�����ַ=002EFBB8
			------------------------------2
			------------------------------1
			Ԫ������Ϊ:dfd
			�����ַΪ=002EFBD0
			ָ����ַ�����ַ=002EFBD4
			------------------------------2
			�밴���������. . .


	 */
	//�ܽ᣺�����������ģ����Ƕ���ָ����ַ������ڴ�ռ�û�й�ϵ
	
	
	system("pause");
	return 0;
}

/*
*(1)�����ķ���
*vector
*list
*map
*�������ڱ������ݣ�
*STL�е��������Է�Ϊ3����
*	1.˳������(Sequence containers)����������������array,vector,deque ,list, Forward-List
*	2.����������Associative Containers��,Ԫ��һ����hi��ֵ�ԣ�ʹ�ü���key������ֵ��value���ر��ʺϲ���
*		set /multiset map/multimap
*		���ݼ��Զ����ڲ������ܿ��Ʋ������ݣ����ǲ��ܿ��Ʋ���λ�á�
*		����ʹ���������߹�ϣ��ʵ��
*		
*	3.����������unordered containers��c++11���Ƴ��������֡�Ԫ�ص�λ�ò���Ҫ����Ҫ����Ԫ���Ƿ���������
*		��������Ҳ������һ�ֹ���������
*		����Ԫ�صĵĲ��룬ÿ��Ԫ���������е�λ�ÿ������ŷ����ı䡣�ڲ�����ʹ�ù�ϣ����ʵ��
*		�������У�unordered_set unordered_multiset unordered_map  unordered_multimap
*	c++��׼û�й涨����ʲô�㷨ʵ����������
*
*(2)������˵��˵����Ӧ��������
*	2.1array��������һ���ڴ�ռ����������飬��С�̶��������������Ĵ�С
*	�����������ģ����Ƕ���ָ����ַ������ڴ�ռ�û�й�ϵ
*
*(3)
*
*
*/