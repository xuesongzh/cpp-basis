#include<iostream>
#include<cstdlib>
using namespace std;

int main011(void)
{
	char*p = NULL;
	char*q = nullptr;

	int number1 = NULL;//����
	//int number2 = nullptr;//error
	if (p==q)	//����������ִ��
	{
		cout << "p��q����null" << endl;
	}
	//���ۣ�����nullptr��Ҫ��Ϊ�˱���0��null֮��Ļ�����nullptr����һ��ָ��

	cout << typeid(NULL).name() << endl;
	cout << typeid(nullptr).name() << endl;
	/*int
	 *std::nullptr_t
	 */
	//���ۣ�null��nullptrʵ�����ǲ�ͬ�����ͣ��ڽ������غ�����ʱ���õ���
	//���ս��ۣ�����ָ��ĳ�ʼ������������ĺ�ָ���йص�NULL���ϣ�����nullptrȡ��NULL
	
	system("pause");
	return 0;
}
/*
* (1)nullptr��c++11�е��¹ؼ���  nullptrҲ�ǿ�ָ��
* Ϊʲô����nullptr��
* ���ս��ۣ�ָ���ʼ����NULL�ĵط�ʹ��nullptr��ʼ��
*/