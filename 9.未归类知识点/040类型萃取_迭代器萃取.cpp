#include<iostream>
#include<iostream>
#include<cstdlib>
#include<functional>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

template <typename T>
void printTraitsInfo(const T& t)
{
	cout << "--------------begin-----------" << endl;

	cout << "����Ҫ��ȡ�����������ǣ�" << typeid(T).name() << endl;

	cout << "is_void = " << is_void<T>::value << endl;                                    //�����Ƿ���void
	cout << "is_class = " << is_class<T>::value << endl;                                  //�����Ƿ���һ��class
	cout << "is_object = " << is_object<T>::value << endl;                                //�����Ƿ��� һ����������
	cout << "is_pod = " << is_pod<T>::value << endl;                                      //�Ƿ���ͨ�ֻࣨ������Ա��������������Ա��������   POD(plain old data)
	cout << "is_default_constructible = " << is_default_constructible<T>::value << endl;  //�Ƿ���ȱʡ���캯��
	cout << "is_copy_constructible = " << is_copy_constructible<T>::value << endl;        //�Ƿ��п������캯��
	cout << "is_move_constructible = " << is_move_constructible<T>::value << endl;        //�Ƿ����ƶ����캯��
	cout << "is_destructible = " << is_destructible<T>::value << endl;                    //�Ƿ�����������
	cout << "is_polymorphic = " << is_polymorphic<T>::value << endl;                      //�Ƿ����麯��
	cout << "is_trivially_default_constructible = " << is_trivially_default_constructible<T>::value << endl;      //ȱʡ�������캯���Ƿ��ǿ��п��޵�(û��Ҳ�е�),����1��ʾȷʵ���п���

	cout << "has_virtual_destructor = " << has_virtual_destructor<T>::value << endl;      //�Ƿ�������������

	cout << "--------------end-------------" << endl;

}

class A
{
public:
	A() = default;
	A(A&& ta) = delete;           //�ƶ����죺��Ҫ��дdelete��ϵͳһ��ͻ���Ϊ���������Ա������
	A(const A& ta) = delete;      //�������� 
	virtual ~A() {}
};
class B
{
public:
	int m_i;
	int m_j;
};
class C
{
public:
	C(int t) {} //���Լ��Ĺ��캯������������������ṩȱʡ���캯��
};

void func()
{
	printTraitsInfo(int());     //��һ����ʱ�����ȥ
	printTraitsInfo(string());
	printTraitsInfo(A());
	printTraitsInfo(B());
	printTraitsInfo(C(1));
	printTraitsInfo(list<int>());
}
int main(void)
{
	func();
	system("pause");
	return 0;
}
/*
* (1)������ȡ����  type traits
* ���ڷ��ͱ�̼�������stlʵ��Դ���У�����������ȡ����ʹ�ñȽ϶ࡣ��ȡ����ȡһ����Ϣ������
* c++��׼��������˺ܶ�������ȡ�ӿڣ���Щ�ӿ���ʵ����һЩ��ģ�塣��
* https://en/cppreference.com/w/cpp/types
* 
* (2)������ȡ����
* ͨ����ȡ�ӿ��е�valueֵΪtrue����false������ȡһЩ���õ���Ϣ��
* 
* (3)��������ȡ����(iteratirs traits)
* ��������������  ���� �ܹ�����������������
*
* (4)�ܽ�
* c++�У�ģ���뷺�ͱ�̣�ģ��Ԫ��̳����ڿ�����׼��ͽӿڿ⿪��������������������Ҫר��ѧϰ��
* ����һ�㶼������ҵ���߼���صĹ�����
* 
*/
