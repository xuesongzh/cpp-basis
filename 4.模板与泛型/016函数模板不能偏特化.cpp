#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;


template<typename T, typename U>
void TestFunction(T &t, U&u)
{
	cout << "--���Ǻ��������汾--" << endl;
}

//ȫ�ػ��汾 t=int��u=doubel
template<typename T>//����д����ֻ��һ�����Ͳ������µ�ģ�壬���Ǿֲ�ƫ�ػ�
void TestFunction(T&t, double&u)
{
	cout << "--���Ǿֲ�ƫ�ػ����ػ��汾--" << endl;
}




int main(void)
{
	//����ģ��ȫ�ػ�
	const char*p = "jisuanjiz";
	int i = 1200;
	TestFunction(p, i);//t=const char* &


	double d = 23.344;

	TestFunction(i, d);//���µ������µ�����ģ�壬�����Ǻ���ƫ�ػ�
	TestFunction(p, d);

	system("pause");
	return 0;
}

/*
*(1)����ģ��ƫ�ػ�--
*����ģ�岻��ƫ�ػ�

*(2)ģ���ػ��汾 ����λ�ý���
*ģ�嶨�塢ʵ��һ�����.h�ļ��У�ģ����ػ��汾�ͷ����汾Ӧ����ͬһ�ļ��С�
*
*�����汾��ǰ���ػ��汾�ں�
*
*(3)
*
*
*/