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

class TescClass
{
public:
	//auto m;//��ͨ��Ա������������auto
	static  const auto m2 = 23;//static const ��̬��Ա����ʹ��auto����ֵ���������ڳ�ʼ��
};


int main(void)
{

	system("pause");
	return 0;
}
/*
* (1)auto�����ó��Ͼ���
*	1.atuo����ʹ���뺯���βΣ�����void myfunction(auto x)
*	2.������ͨ��Ա��������ʹ��auto ��static const �������Ǳ��������ڳ�ʼ��
*	
* (4)
* (5)
* (6)(7)
*/