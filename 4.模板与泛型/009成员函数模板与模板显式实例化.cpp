#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;


class A
{
public:
	template <typename T>
	void myFunction09(T tem)//��Ա��������ģ��
	{
		cout << tem << endl;
	}
	
};


//�౾�����ģ�����C����Ա��������ģ�����T1��T2
template <typename T3>
class B
{
public:
	template <typename T>
	void myFunction09(T tem)//��Ա��������ģ��
	{
		cout << tem << endl;
	}


	//���캯��ģ��
	template <typename T2>
	B(T2 v1, T2 v2);
	
	void mytestFunction09()
	{
		cout << "����B��Ĳ��Ժ���" << endl;
	}
	
public:
	T3 c1;
};

//���캯��
template <typename T3>//��д���ģ������б�
template<typename  T2>//��д�����Լ���ģ������б�
B<T3>::B(T2 v1, T2 v2)
{
	cout << v1 << endl;
	cout << v2 << endl;
}

//����ģ��
template <typename T4>
void myFunction009(T4 t)
{

	cout << t << endl;
}



/*��3��
1.��ʽʵ����  --ʵ�������壬ֻ��Ҫ��һ��.cppֻ��������Ϳ��ԣ�
������һ������������ʵ����һ���������

2.������.cpp�ļ��С���ʽʵ����������
extern template B<double>;		--ģ��ʵ���������������ڱ��ļ�������һ��ʵ�������룬������cpp�ļ����Ѿ���һ��ʵ�����汾��
���������汾��ʵ�������Դ�������cpp�ļ��У���int float double���͵�
�ܽ᣺һ��cpp�ж��壬����cpp�ж���������
*
 */


//��ʽʵ������ģ��
template B<double>;

//��ʽʵ��������ģ��
template void myFunction009(int t);



int main(void)
{
	//(1)
	A a;
	//���õ�ʱ�򣬱������Ż�ʵ����ģ��
	a.myFunction09(3);//�������Զ��ƶ�--int
	a.myFunction09<double>(3.2343);

	//(2)
	//��ģ���������<>��ָ��������ģ������ܶ�ʱ������ƶϳ���
	B<double> b1(2, 3);//���캯��ģ�������Զ��ƶ�int


	//(3)ģ����ʽʵ����
	

	system("pause");
	return 0;
}

/*
*(1)��ͨ��ĳ�Ա����ģ��
*��������ͨ�࣬������ģ�壬���ĳ�Ա������������һ������ģ�壬��Ϊ����Ա����ģ�塱�����������麯����
*
*(2)��ģ��ĳ�Ա����
*��ģ��ĺ�������ģ�庯��+��ͨ��Ա������ֻ�б����õ�ʱ��Ż�ʵ���������������δʹ�ã��򲻻�ʵ�����ó�Ա������
*
*(3)ģ����ʽʵ����
*ÿ��cpp���Ƕ�������ġ�
*ͬʱΪ�˷�ֹ���.cpp�ж�ʵ��������ͬ����ģ�壬����c++�ṩ��һ������취��
*��ʱ�����Ҫ��ʽʵ������
*
*�ܽ᣺
*1�������ɫ������ʵ�ֲ����ã�������ʹ�ã���ʶ���ɡ�
*
* Sunrise�ڶ���������ѧ�ڶ���ѧ¥1121ʵ����
* 2019��11��24��22:28:05
*
*/