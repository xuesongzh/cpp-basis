#include<iostream>
#include<cstdlib>

using namespace std;

template<typename T>
void myFunction(T&&tem)
{}

int main(void)
{
	int ix = 12;//ix����ֵ
	int&&reference = std::move(ix);//��ֵת��Ϊ��ֵ��
	int&&reference02 = std::forward<int>(ix);//ok ���԰���ֵ�ɹ���ת��Ϊ��ֵ

	myFunction(ix);//i����ֵ��T=int&,tem=int&
	myFunction(100);//100����ֵ��T=int,tem=int&&

	/*std::forward<int>(ix);ת�����ǲ�ת����ȡ����<>�����ֵ������������������ã�
	 *14����T=int,tem=int&&����
	 * 
	 */
	
	system("pause");
	return 0;
}
/*
* (1)std::forward�÷�����
*		Ӧ����ģ��ת������	��һ��ֵת��Ϊԭʼʵ�ε�����
* (2)
* (3)
* (4)
* (5)
* (6)(7)
*/