#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include <memory>

using namespace std;


unique_ptr<string>myFunction()
{
	unique_ptr<string>pr(new string("dsfsdf"));
	return  pr;
	/*
	 * �Ӻ�������һ���ֲ�����ϵͳ����������һ����ʱunique_ptr���󣬵���unique_ptr���ƶ����캯��
	 * 
	 */
}

void myDelete(string *pdel)
{
	delete pdel;
	pdel = nullptr;
}
typedef void(*myf)(string *);
//���庯��ָ������ using myf=void(*)(string*)
//typedef decltype(myDelete)*myf;

//lambda���ʽ
auto mydel=[](string*del)
{
	delete del;
	del = nullptr;
};


int main(void)
{
	unique_ptr<string> p1;
	p1 = myFunction();//��ʱ����ֱ�ӹ�����p1�С������ܻ��ͷŵ���ʱ��������ָ����ڴ�ռ䡣


	//ָ��ɾ����--ȡ��ϵͳĬ�ϵ�ɾ����
	unique_ptr<string, myf> p2(new string("jisuanj"), myDelete);

	//��һ��д��
	unique_ptr<string, decltype(myDelete)*>p3(new string("jisann"), myDelete);
	//��lambda���ʽ��д���������ɴ���operator()���͵������
	unique_ptr<string, decltype(mydel)>p4(new string("sdfdsf"), mydel);
	
	//unque_ptr����ָ����ͬ
	string *p = nullptr;
	cout << sizeof(p) << endl;//4
	unique_ptr<string>p5(new string("sdf"));
	cout << sizeof(p5) << endl;//4
	
	system("pause");
	return 0;
}

/*
*(1)����unique_ptr����ָ��
*�ǲ��ܿ�����Ҫ�����ٵ�ʱ�򣬻��ǿ��Կ����ģ�������Ǵ�һ����������һ��unique_ptr
*
*(2)ָ��ɾ����
*	1.ȱʡ����£�����delete�ͷ��ڴ�ռ�
*	unique_ptr<ָ���Ķ������ͣ�ɾ����>����ָ���������
*	ɾ������������һ���ɵ��ö���
*	shared_ptrɾ����ֱ���ڲ���������Ϻ������ּ��ɡ�����unique_ptr��ɾ������Ը���һ�㡣
*	��Ҫ����ģ���д��ݾ������ͺ�ɾ���������͡�
	unique_ptr<string, myf> p2(new string("jisuanj"), myDelete);
*
*	2.ָ��ɾ��������˵��
*		shared_ptrָ����ɾ������ͬ������ָ��Ķ���������ͬ������shared_ptr����ͬһ�����͡�
*		����unique_ptr�����Ͱ���ɾ������Ҳ��˵��ɾ������ͬ��unique_ptr����ͬһ�����͡�
*
*(3)�ߴ�����
*	shared_ptr����ָ���2��������unque_ptr����ָ����ͬ.����ɾ������ͬ����ռ���ڴ�ռ䲻ͬ
*	lambda --4�ֽ�,
*	����ָ������--8�ֽ�
*	�����ֽڶ�Ч����Ӱ�죬�Զ���ɾ����Ӵ������ʹ�á�
*	shared_ptr����ָ��ʲôɾ����������ָ���2����
*
*(4)����ָ���ܽ�
*	4.1����ָ�뱳������˼��
*		��ҪĿ�ģ����������ͷ��ڴ棬��ֹ�ڴ�й©��
*	4.2auto_ptrΪʲô��������	--������⣬��Ĭ��ת������Ȩ
*		c++98ʱ��������ָ�룬����unique_ptr����ָ���һ���ֹ��ܡ�
*		�Ҳ����������б��棬�����ܴӺ����з��ء�
*		��Ȼunique_ptr��auto_ptr���Ƕ�ռʽ�ģ�����auto_ptr���и�ֵ����=��Ĭ��ת������Ȩ��
*	���飺ʹ��unique_ptrȡ��auto_ptr
*	
*	4.3����ָ���ѡ��
*		shared_ptr
*		unique_ptr
*		��������ж��ָ��ָ��ͬһ������ʹ��shared_ptr
*		�������Ҫ���ָ��ָ��ͬһ��ָ�룬ʹ��unique_ptrָ��
*	
*
*
*/