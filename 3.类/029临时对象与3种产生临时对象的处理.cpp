#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

class TestClass
{
public:
	int value01;
	int value02;
	
public:
	TestClass() { ; }
	TestClass(int value01=0,int value02=0)
	{
		this->value01 = value01;
		this->value02 = value02;
		cout << "�����˴������Ĺ��캯��" << endl;
	}
	
	TestClass(const TestClass&tem):value01(tem.value01),value02(tem.value02)//�������캯��
	{
		cout << "�������캯��ִ��" << endl;
	}
	virtual ~TestClass()
	{
		cout << "��������������" << endl;
	}
	//������ֵ�����
	TestClass&operator=(const TestClass&temc)
	{
		this->value01 = temc.value01;
		this->value02 = temc.value02;
		cout << "�����˿�����ֵ�����" << endl;
		return *this;
	}
public:
	//int Add(TestClass& tc)
	int Add(TestClass tc)
	{
		//��ͨ����
		int tem = tc.value01 + tc.value02;
		cout << tem << endl;
		return tem;	//�����������������tc�����ʱ������������Ϊ����������ʱʹ����һ��
		
	}
	
		
};

//ͳ���ַ�ch��strsource������ֵĴ������Ѵ������ػ�ȥ
//ȥ��const--�޷��� "char [128]" ���͵�ֵ��ʼ�� "std::string &" ���͵�����(�ǳ����޶�)--ϵͳ��Ϊ����޸���ʱ���������	
int countCh(const string &strsource,char ch)
{
	const char*p = strsource.c_str();
	int iCount = 0;

	return iCount;
}

//�����Ա�Ϊԭ��2��
TestClass DoubleTestClass(TestClass&tc)
{
	TestClass te(0,0);//�����һ�ι��캯�������������ĵ���
	te.value01 = tc.value01 * 2;
	te.value02 = tc.value02 * 2;
	return te;	//�����˿������캯��������һ����ʱ���󣬷��غ󲢵����������������û�н��գ�
	//�Ż�
	//return TestClass(tc.value01 * 2, tc.value02 * 2);
}
int main(void)
{


	int number01 = 100;
	int&&reference01 = number01++;
	//��ֵ���ã�reference01��number01û�й�ϵ�ˣ�
	reference01 = 2032;


	//1.�Դ�ֵ��ʽ���������ݲ���
	TestClass testclass01(12, 12);	//���ÿ������캯��
	int sum = testclass01.Add(testclass01);	//���ÿ������캯��
	cout << "sum=" << sum << endl;



	//2.����ת��������ʱ����--��ʽ����ת���Ա�֤�������óɹ�

	TestClass testclass02(21,32);
	testclass02 = 2000;//��һ�в�����һ����ʱ��������˹��캯������Ĭ�ϲ���������������
	/*
	 *  �����˴������Ĺ��캯��
		�����˿�����ֵ�����
		��������������
		ִ����3��������
			1.ʹ��2000������һ����ʱtestClass����
			2.���ÿ�����ֵ���������ʱ�����ֵ��ֵ��testclass02����
			3.����������������testclass02����
	 */
	//�Ż�����--�Ѷ������͸�����ֵ����һ����
	cout << "------------------------------" << endl;
	TestClass testclass03 = 1000;	//ֻ�����˹��캯��
	/*
	 * ����testclass03����ϵͳ�ͷ������ڴ�ռ䡣
	 * ��1000����testclass03����ֱ���ڷ�����ڴ�ռ���䣬û�в�����ʱ����
	 */

	
	//��ʽ����ת���Ա�֤�������óɹ�
	char mystr[128] = "chchjjjjjjjooooo";
	int result = countCh(mystr, 'o');//���������Զ�����һ��string���͵���ʱ���󣬴��ݹ�ȥ
	/*ϵͳֻ��Ϊconst string &strsource������ʱ������������Ϊ��const����string &strsource������ʱ����
	 */


	//3.�������ض�������

	TestClass test_class04(23, 34);
	test_class04=DoubleTestClass(test_class04);
	//���������ʱ������ÿ�����ֵ������������и�ֵ���Ͳ��������������

	//���ʹ����ֵ����������
	TestClass &&test_class05 = DoubleTestClass(test_class04);//��ʱ���󲻻ᱻ����,��Ϊ�����ã����Բ�����ÿ�����ֵ�����
	system("pause");
	return 0;
}

/*
*(1)��ʱ����ĸ���
*	++i������ֵ���ʽ
*	i++������ֵ���ʽ(һ����ʱ��������ʹ��Ŀ�ģ�Ȼ��i=i+1)
*
*ʲô����ʱ����ΪʲôҪ�ٲ�����ʱ����
*
*	����һЩ��ʱ��������Ϊ���Ǵ�����д����������ģ�ͳ����ʱ����Ϊ��ʱ����
*	��ջ�Ϸ������ʱ���󣬲��������ֹ�ȥ�ͷţ�������ʱ���������Ӱ������Ч�ʡ�
*	��Щ��ʱ���������Ǻ�������ѧϰ�Ļ�����
*	
*	
*
*(2)������ʱ���������ͽ��
*	1.�Դ�ֵ��ʽ���������ݲ���--����ÿ������캯��
*		����Ż�����Ϊ����
*	2.����ת��������ʱ����--��ʽ����ת���Ա�֤�������óɹ�
*	3.�������ض�������
*
*		��ʱ����û�н��գ������̵���������������������н��գ����ܵ��ÿ�����ֵ����������ò����á�
*
*
*
*2019��11��22��21:42:59
* Sunrise�ڶ���������ѧ�ڶ���ѧ¥1121ʵ����
*


*
*/