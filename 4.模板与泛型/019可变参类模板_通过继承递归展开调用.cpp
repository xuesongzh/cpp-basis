#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

//1.ʹ�õݹ�̳з�ʽչ��������
template<typename ...Args>class myclass{};//��ģ��
//��дһ������Ϊ0���ػ��汾
template<>class myclass<>//0��ģ������ػ��汾
{
public:
	myclass()
	{
		cout << "0��ģ������ػ��汾ִ��"<<this << endl;
	}
};

template<typename First,typename ...Other>
class myclass<First,Other...>:private myclass<Other...>
{
public:
	myclass():m_i(0)
	{
		cout << "myclass�Ĺ��캯��ִ����"<<this << endl;
	}
	//�вι��캯��
	myclass(First parf,Other...Paro):m_i(parf),myclass<Other...>(Paro...)//���ø���Ĺ��캯��
	{
		cout << "�в������캯��ִ��"<<this << endl;
	}
	
	
public:
	First m_i;
	
	
};

int main(void)
{
	myclass<int, float, double>myc;
	/*
	 * ִ�����ι��캯��
	 * myclass<int,float,double>--->myclass<int ,float>--->myclass<int>
	 *
	 * 	0��ģ������ػ��汾ִ��0020F73C
		myclass�Ĺ��캯��ִ����0020F73C
		myclass�Ĺ��캯��ִ����0020F73C
		myclass�Ĺ��캯��ִ����0020F73C
	 */
	cout << "----------------" << endl;
	myclass<int,float,double> my_class01(12, 123.565, 344.5845734958);
	/*
	 * 0��ģ������ػ��汾ִ��0039F74C
		�в������캯��ִ��0039F74C
		�в������캯��ִ��0039F74C
		�в������캯��ִ��0039F74C
	 */

	system("pause");
	return 0;
}

/*
*(1)�ɱ����ģ��
*����ģ���ж���0���������ģ������������и߼����⣬ʹ�ò��ࡣ
*	1.ʹ�õݹ�̳з�ʽչ��������
	
ÿ�����඼�ֳ�1+�������Ϊ0�����еݹ����.

ע��ݹ�̳�
*	
*
*(2)��������ʾ������ʹ��dumbin /all �ļ����� >mytext.txt
*�鿴�ж��������ɡ�
*
*(3)2019��11��25��21:49:17
* Sunrise�ڶ���������ѧ�ڶ���ѧ¥1121ʵ����

*
*
*/