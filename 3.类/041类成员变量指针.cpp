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

	virtual void Function(int value)
	{
		cout << "VirtualFunction ������" << endl;
	}

	static void StaticFunction(int value)
	{
		cout << "StaticFunction������" << endl;
	}
	int number;
	static int Static_number;
};
int TestClass::Static_number = 100;

int main(void)
{
	//������ͨ��Ա������
	int TestClass::*p1 = &TestClass::number;//����һ����ͨ��Ա������ָ��,��Ҫ�������ض��Ķ�����
	//p1 = 0x00000004 {???}--������һ�����������ϵ�ָ�룬�Ǹó�Ա���������������ƫ������
	//��Ϊ��Ա�������麯����������Ϊ�������麯�������������һ���麯����ָ��ռ��4���ֽ�ָ���麯����
	//��Ա���������������
	TestClass tc;
	tc.*p1 = 202;//ͨ�����Ա����ָ�����޸ĳ�Ա������ֵ���ȼ���
	//tc.number = 202;


	//���ھ�̬��Ա����--������,���������ڴ��ַ��
	int*staticPoint = &TestClass::Static_number;
	//staticPoint = 0x00c6b000 s�Ǹ��������ڴ��ַ
	*staticPoint = 400;
	//�ȼ���
	//TestClass::Static_number = 400;
	
	

	system("pause");
	return 0;
}

/*
*(1)���Ա����ָ��
*	��Щ�漰��c++����ģ�͵ȣ�
*
*
*/