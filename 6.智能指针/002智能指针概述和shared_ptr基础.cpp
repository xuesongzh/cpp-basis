#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include <memory>

using namespace std;

shared_ptr<int> testFunction(int value)
{
	//return new int();//error�������Խ�new�õ���int*����ת��Ϊshared_ptr
	return shared_ptr<int>(new int(value));//OK��ǿ������ת��
}

int main(void)
{
	//shared_ptrָ���÷�
	shared_ptr<int>p1(new int(100));//p1ָ��ֵΪ100��int�����ڴ�ռ�
									//shared_ptr<int>p2 = new int(100);//error����ָ����explicit,�����Խ�����ʽ����ת����
									//=һ��������ʽ����zhuanhaun


									//����ֵ��shared_ptr
	shared_ptr<int> p2 = testFunction(234);

	//��ָ����Գ�ʼ��shared_ptr,���ǲ��Ƽ�
	string* s1 = new string("23432434");
	shared_ptr<string>s2(s1);
	//����ʹ��
	shared_ptr<string>s3(new string("sdfdsf"));

	//�յ�shared_ptrָ��
	shared_ptr<int>p3;//ָ��int������ָ�룬������ĿǰΪ��==nullptr

					  //(3)make_shared
	shared_ptr<int>p4 = make_shared<int>(1345);//shared_ptrָ��һ��ֵΪ100�������ڴ�ռ䡣
	shared_ptr<string>p5 = make_shared<string>(5, 'a');//p5ָ��aaaaa���ַ����ڴ�ռ�
	shared_ptr<int>p6 = make_shared<int>();//p6ָ��һ���ڴ�ռ�int=0
	p6 = make_shared<int>(1000);
	/*p6ָ��һ���µ�int�����ͷ�ָ��0���ڴ�ռ䣬Ȼ��ָ��intֵΪ1000���ڴ�ռ䡣
	*
	*/

	system("pause");
	return 0;
}

/*
*ptr==pointer����д
*
*(1)����ָ������
*��������
*if()
*{
*	.....
*	return ;
*}
*delete p��//ִ�в�������
*
*���ָ��ָ��ͬһ���ڴ�ռ䣬�ͷ��ڴ�ֻ���ͷ�һ�Ρ�
*����new delete��д��Ҫʮ��С�ģ�ҪСС�����ͷţ�ҲС�������ͷš�
*
*��ָ�룺ֱ��new���ص�ָ�롣û�о����κΰ�װ������ָ��ǿ�������ǿ�����Ҫȫ��ά����
*��������ָ������ָ��ĸ������⡣
*����ָ�룺�����ɶ���ָ������˰�װ����װ��
*��ͻ���ŵ㣺����ָ�롰�ܹ��Զ��ͷ���ָ��Ķ����ڴ档�����õ���new�������ڴ������ͷš�
*
*���飺����ʹ������ָ�룬ʹ������ָ��ĳ�������ױ�д�͵��ԡ�
*
*c++����4������ָ�룺
*auto_ptr��c++98��
*unique_ptr(c++11)
*shared_ptr(c++11)
*weak_ptr(c++11)
*�������ǽ��ж�̬���������������ڵĹ����ܹ���Ч��ֹ�ڴ�й©��
*
*c++11��׼�з���ʹ��auto_ptr;Ŀǰauto����ptr�Ѿ���ȫ��unique_ptrȡ����
*c++11�е�3������ָ�붼����ģ�壬���ǿ��Խ�new��õĵ�ַ��ֵ������
*�ص���shared_ptr������ʽָ��--���ָ��ָ��ͬһ���������һ��ָ�뱻����ʱ���ͷŶ�����ڴ�ռ䡣
*weak_ptr�Ǹ���shared_ptr;
*unique_ptr��ռʽָ�룬��һ��ʱ���ڣ�ֻ��һ��ָ���ܹ�ָ��ö��󣬸ö��������Ȩ�ǿ����ƽ���ȥ�ġ�
*
*������delete��ʱ������ָ�����delete������˵���㲻��Ҫ�ֶ�delete�ˡ�
*
*(2)shared_ptr����
*��������Ȩ--���Ǳ�һ��shared_ptrӵ�У����Ƕ��shared_ptr֮���໥Э����
*����ԭ�����ü�����ÿ��shared_ptr��ָ����ͬ���ڴ棬�������һ��ָ����Ҫָ��ö����ʱ��
*��ô���һ��share_ptrȥ�ͷŸö���
*
*���һ��ָ������shared_ptr��ʲô������ͷŸö���shared_ptr��ָ��Ķ��󣩣�
*	1.shared_ptr�������ڽ�����������ʱ��
*	2.���shared_ptrָ�����������ʱ��
*	���ֲ���������java�е��������ջ��ơ�
*����ģ��,<>�������ָ�����ָ������ͣ�����ٸ�����ָ������
*��ʽ��shared_ptr<ָ�������>����ָ������
*
*
*(3)make_shared��������׼������ĺ���ģ�壬��ȫ��Ч�����ʹ��shared_ptr
*�ܹ��ڶ��з����ڴ沢��ʼ��һ������Ȼ�󷵻�ָ��˶����shared_ptr
*make_shared�����Զ���ɾ�����������Ҫ�Զ���ɾ������ʱ�򣬲���ʹ�á�
* Sunrise�ڶ���������ѧ�ڶ���ѧ¥1121ʵ����
* 2019��11��26��22:03:05
*
*
*/