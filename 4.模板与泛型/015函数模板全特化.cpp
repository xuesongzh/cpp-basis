#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;


template<typename T,typename U>
void TestFunction(T &t,U&u)
{
	cout << "--���Ǻ��������汾--" << endl;
}

//ȫ�ػ��汾 t=int��u=doubel
template<>//ȫ�ػ�������Ϊ��
void TestFunction(int &t, double&u)
{
	cout << "--����int double���͵��ػ��汾--" << endl;
}


void TestFunction(int &t, double&u)
{
	cout << "����testFunction�����غ���" << endl;
}

int main(void)
{
	//����ģ��ȫ�ػ�
	const char*p = "jisuanjiz";
	int i = 1200;
	TestFunction(p, i);//t=const char* &
	

	double d = 23.344;
	TestFunction(i, d);//����int double ���ػ��汾
	//��������غ��������ȵ������غ���������ȥ�����������ĺ���

	system("pause");
	return 0;
}

/*
*(1)����ģ��ȫ�ػ�
*ȫ�ػ�����ʵ��ɽ�ȼ���ʵ����һ������ģ�壬�����ǵȼ���һ����������
*
*�ػ������������غ������ȵ�����һ��������
*
* Sunrise�ڶ���������ѧ�ڶ���ѧ¥1121ʵ����2019��11��25��15:58:46
*
*(2)
*
*(3)
*
*
*/