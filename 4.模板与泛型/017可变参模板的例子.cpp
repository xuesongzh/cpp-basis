#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

//�ɱ�κ����ļ�����
/*
 * 1.��ôһ���args��Ϊһ������һ�Ѳ�����������Щ���������ǿ��Բ�ͬ�ġ�
 * 2.�������T�������ͣ���Ҫ���Ϊһ�����ͣ�����0��������͡�
 * 3.һ�������п�������0�����ģ�������������Щģ������������������͡�
 * 4.ע�⣺
 *	T...   �ɱ�����ͣ���һ������
 *	args�ɱ��βΣ�һ���β�
 *5.&��λ�ó���������������
 */
template<typename ... T>
void myFunction(T...args)
{
	cout << "args=" <<sizeof...(args) << endl;
	cout << sizeof...(T) << endl;
}


//����2
template<typename T,typename ...U>
void myFunction02(const T&firstarg,const U&...otherargs)
{
	cout << sizeof...(otherargs) << endl;//sizeof...�ɱ�ε�����
}

void func()
{
	myFunction();
	myFunction(10, 20);
	myFunction(10, 20,23,4343.34);
	cout << "----------------------------------" << endl;

	myFunction02(1, 23, 43);//2,������һ������
}

int main(void)
{
	func();
	system("pause");
	return 0;
}

/*
*(1)�ɱ�κ���ģ�� variadic templates
*����ģ���а���0���������ģ����������﷨�Ϻʹ�ͳ��ģ�岻һ����ʹ��  ...
*
*
*(3)
*
*
*/