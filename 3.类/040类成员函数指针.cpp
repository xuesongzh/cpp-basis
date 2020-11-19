#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

class TestClass
{
public:
	void CommanFunction(int value)
	{
		cout << "��ͨ��Ա����������" << endl;
	}
	
	virtual void VirtualFunction(int value)
	{
		cout << "VirtualFunction ������" << endl;
	}

	static void StaticFunction(int value)
	{
		cout << "StaticFunction������" << endl;
	}
};

int main(void)
{

	//����һ����ͨ�����Ա����ָ��
	void (TestClass::*myCommanPointor)(int);//����һ��ָ����ͨ������ָ��
	myCommanPointor = &TestClass::CommanFunction;//ָ�����еĳ�Ա����
	/*
	 * ��Ա������������ģ������ڳ�Ա���������ھ��г�Ա������ַ���ڡ�
	 *	��Ҫ���ΪҪ�ȴ���һ�������
	 *	����Ҫ�ó�Ա����ָ�룬�ͱ����������һ��������ϡ�
	 *	ʹ�ú���ָ��ĸ�ʽ��
	 *	���������.*����ָ���������������
	 *	����Ǹ�����ָ�룬����ø�ʽ"ָ����->*����ָ�������"������
	 */

	TestClass tc, *ptc;
	ptc = &tc;
	(tc.*myCommanPointor)(199);//����tc������ָ�������ָ��ĳ�Ա����
	(ptc->*myCommanPointor)(123);//�����ָ�����ָ�������ָ��ĳ�Ա����

	//ָ���Ա�麯����ָ��--��������ͨ����ָ����ͬ
	void(TestClass::*myVirtualPointor)(int);//�麯��ָ��
	myVirtualPointor = &TestClass::VirtualFunction;//"������������ڴ��ַ"
	(tc.*myVirtualPointor)(200);//�󶨵�������ϵ��������麯��
	(ptc->*myVirtualPointor)(201);

	/*
	 * ���ھ�̬��Ա����
	 * ʹ�ã�
	 * 1.ʹ�á�*����ָ�����������������̬��Ա����ָ�루��Ϊ������һ����ģ�
	 * 2.ʹ�á�&����������Ա������������ȡ��Ա��̬������ַ
	 * 
	 */
	//����һ����̬��Ա����ָ�벢��ֵ
	void(*myStaticPointor)(int) = &TestClass::StaticFunction;
	//����Ҫ�����ֱ�ӵ���
	myStaticPointor(100);
	
	
	system("pause");
	return 0;
}

/*
*(1)���Ա����ָ��
*ͨ�׵Ľ���һ��ָ�룬ָ�����Ա����
*	1.��ͨ��Ա����
*	��������ֵ �����ͣ���*����ָ���������   ������ͨ��Ա����ָ��
*	&����������Ա������		����ȡ��Ա�����ĵ�ַ--�����Ǹ��������ڴ��ַ��
*	2.��̬��Ա����
*	3.�麯��ָ�����

 Sunrise�ڶ���������ѧ�ڶ���ѧ¥1121ʵ����
2019��11��23��22:16:46

*
*
*/