#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

//1.ʹ�õݹ���Ϸ�ʽ��ʽչ��������
template<typename ...Args>class myclass {};//��ģ��
										   //��дһ������Ϊ0���ػ��汾
template<>class myclass<>//0��ģ������ػ��汾
{
public:
	myclass()
	{
		cout << "0��ģ������ػ��汾ִ��" << this << endl;
	}
};

template<typename First, typename ...Other>
class myclass<First, Other...> //:private myclass<Other...>
{
public:
	myclass() :m_i(0)
	{
		cout << "myclass�Ĺ��캯��ִ����" << this << endl;
	}
	//�вι��캯��
	myclass(First parf, Other...Paro) :m_i(parf),m_o(Paro...)//, myclass<Other...>(Paro...)//���ø���Ĺ��캯��
	{
		cout << "�в������캯��ִ��" << this << endl;
	}


public:
	First m_i;
	//��Ϲ�ϵ
	myclass<Other...>m_o;//�������������Ų����ٵ���
};



int main(void)
{
	myclass<int, float, double> myclass01(1, 23.32, 34.545);
	/*
	 * 0��ģ������ػ��汾ִ��0041FA94
	�в������캯��ִ��0041FA8C
	�в������캯��ִ��0041FA84
	�в������캯��ִ��0041FA7C

	��Ϲ�ϵ�����׵�ַ����һ��
	 */
	
	system("pause");
	return 0;
}

/*
*(1)ͨ���ݹ���Ϸ�ʽչ��������
*
*(2)
*
*(3)
*
*
*/