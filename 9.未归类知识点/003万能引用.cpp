#include<iostream>
#include<cstdlib>

using namespace std;

template <typename T>
void myFunction(const T&value)//value��������const T&
{
	return;
}

void myFunction02(int&& tem)//��������ֵ��������
{
	cout << "��ֵ���ú���" << endl;
	return;
}

/*�޸ĺ���ģ���tem�ȿ��Խ�����ֵ���ֿ��Խ�����ֵ��
*tem��������T&&
*�ӱ���δ��������жϣ�T���ƶϳ�����������int���ͣ���int&&tem,����temֻ�ܽ�����ֵ��
*������ֵ���������ƶ�ΪT&���� int&
*������ֵ���������ƶ�ΪT&&���� int&&
*/
template<typename T1>
//void myFunction03(const T1 &&tem)
void myFunction03(T1 &&tem)//&&����tem���͵�һ���֣�&&��T����û�й�ϵ
{
	cout << "��ֵ����ģ�庯��" << endl;
	return;
}

//��ģ��
template<typename T2>
class myTest
{
public:
	void testFunction(T&& tem)//�������ֵ����
	{
		
	}

	template<typename T3>
	void testFunction02(T3&& tem)//�������������
	{
		
	}
};

int main(void)
{
	myFunction(12);//T��ʲô���ͣ�value��ʲô���ͣ�  T��value������������ͬ��
	/*
	 * T��int���ͣ�value��������const int&����
	 * ���ú���ģ��ʱ����Ĳ���10���T�����Ͳ���Ӱ�졣
	 * value�����ͻ��T�����Ͳ���Ӱ�졣--value������Ϊ�������ã��ͻ��T���Ͳ���Ӱ��
	 */

	//(2)��ֵ����&&
	int&&number01 = 23;
	myFunction02(123);
	//myFunction02(number01);//error number01��һ����ֵ

	myFunction03(123);
	myFunction03(number01);//����ģ��ʱ����Դ�����ֵ
	
	int number02 = 12;
	myFunction03(number02);//int&&��ֵ��������

	//������������ auto
	auto &&number03 = 234;


	//(5)
	myTest<int>mt;
	int i = 100;
	//mt.testFunction(i);//error����Ϊ��������ʱ���Ѿ�ָ������Ϊint�����治��������ģ�����������û���漰�������ƶϡ�
	//��ģ��ʵ�����󣬳�Ա�����о������ͣ�����Ϊvoid testFunction(int&& tem)��
	
	cout << "helloWorld" << endl;
	system("pause");
	return 0;
}

/*
 *(1)���������������
 *�����ǰ��չ涨�Ĺ����ȡ�ڴ������ֵġ�
 *
 *(2)universal reference �������ã�δ�������� ������ʶ
 *	����������Ҫ���ﾳ��
 *		1.�����Ǻ���ģ��
 *		2.���뷢����ģ�������ƶϲ��Һ����βεĵ������� T&&��autoҲ�����������ã�  Tģ�����Ͳ���
 *	T&&����������������
 *(3�������ú���ֵ���õ�����
 *	1.��ֵ���ã���������Ҫ������ֵ���������������
 *	2.����������Ϊ�����β�ʱ�����ǿ��Ը���������ֵ��Ҳ���Դ�����ֵ
 *		������Ǵ��ݽ�ȥ��ֵ����ô����������þͱ������ֵ����
 *		������Ǵ��ݹ�ȥ��ֵ������������þͱ����ֵ����
 *	��ֵת��Ϊ��ֵstd::move()
 *		
 *(4)�ж������ǲ�����������
 *		1.void func(int&&parm)//��ֵ���ã���Ϊû��ģ��
 *		2.template<typename T>
 *		  void func(T&&parm)
 *		  {}//���������ã���ģ�����
 *
 *		3.template<typename T>
 *		  void func(std::vector<T>&& parm)
 *		  {}//��ֵ���ã�ģ������T�������&&���ţ���һ����ֵ����
 *
 *(5)���������ʸ�İ���ͱ���
 *	1.���᣺const������Ϊ��ֵ���õ��ʸ�ʹ���Ϊ��ֵ����  void myFunction03(const T1 &&tem)
 *	2.���ϣ���ĳ�Ա��������
 *	2019��12��9��11��23��
 */