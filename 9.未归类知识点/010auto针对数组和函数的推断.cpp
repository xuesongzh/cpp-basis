#include<iostream>
#include<cstdlib>

#include <boost/type_index.hpp>

using namespace std;

//��ʾ�������ͣ����ﲻ�о�boost��
template<typename T>
void myFunction01(T&tem)//T������ģ�������T�������͵�,tem���βΣ�temҲ�������͵�
{
	using boost::typeindex::type_id_with_cvr;
	cout << "T type=" << type_id_with_cvr<T>().pretty_name() << endl;//��ʾT����
	cout << "tem type=" << type_id_with_cvr<decltype(tem)>().pretty_name() << endl;//��ʾT����

}

void myFunction(double a,int b)
{
	
}


int main(void)
{
	const char myStr[] = "jisuanjizuchengyaunli";//mystr=const char[����]����
	auto mystr02 = myStr;//const char*
	auto&mystr03 = myStr;//const char(&)[���鳤��]����

	int a[2] = { 1,2 };
	auto myIntarry = a;//auto =int* myIntArray=int*

	//��������
	auto myf = myFunction;//
	auto &myf02 = myFunction;//
	using boost::typeindex::type_id_with_cvr;
	cout << "myf type=" << type_id_with_cvr<decltype(myf)>().pretty_name() << endl;//��ʾ����
	cout << "myf02 type=" << type_id_with_cvr<decltype(myf02)>().pretty_name() << endl;
	/*
	    myf type=void (__cdecl*)(double,int)//����ָ��
		myf02 type=void (__cdecl&)(double,int)//��������
	 */

	
	system("pause");
	return 0;
}
/*
* (1)auto�������ͺ������ƶ�
* (3)
* (4)
* (5)
* (6)(7)
*/