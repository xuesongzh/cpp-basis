#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include <memory>

using namespace std;

class A
{
public:
	A(){}
	~A()
	{
		;
	}
};

auto myFunction()
{
	return unique_ptr<string>(new string("jisuanjiz"));//���Ǹ���ֵ
	//��ʱ��������ֵ
}

int main(void)
{
	unique_ptr<int>p1;//ָ��һ����ָ��
	if (p1==nullptr)
	{
		cout << "p1�ǿ�ָ��" << endl;

	}
	unique_ptr<int>p2(new int(34354));//p2ָ��һ��ֵΪ34354��int����
	//make_unique c++14�����룬����Ҫָ��ɾ������ʱ��ѡ�����
	unique_ptr<int>p3 = make_unique<int>(234);
	auto p4 = make_unique<int>(200);//p4��һ������ָ��

	//2.1
	unique_ptr<string>p5(new string("jisuanjizuchengyaunli"));
	//����ָ�벻֧�ֿ�������,Ҳ��֧�ָ�ֵ����
	//unique_ptr<string> p6(p5);//error
	//unique_ptr<string>p7 = p5;//error

	//2.2�ƶ�����
	unique_ptr<string>p8 = std::move(p5);//p5Ϊ�գ�p8ָ��ԭ�����ڴ�ռ�

	//2.3 release()�ͷ�
	unique_ptr<string>p9(p5.release());//ʹ��p5����ָ������ʼ��p9
	string *p10 = p9.release();
	delete p10;//һ��release()����Ҫ�ֹ��ͷ�
	
	//2.4
	unique_ptr<string>p11(new string("dsfsdf"));
	//p11.reset();//�ͷ��ڴ�ռ䣬
	p11.reset(p5.release());//release�ͷ�p5ָ����ڴ�ռ����ϵ��ͬʱp11ָ������ռ�
	
	//2.5nullptr
	unique_ptr<int>p12(new int(234));
	p12 = nullptr;

	//*2.6ָ��һ������
	unique_ptr<int[]>pArray(new int[123]);
	pArray[0] = 0;
	pArray[1] = 0;

	unique_ptr<A[]>pAA(new A[10]);//�����Լ�����������<>����������[]������ᱨ�쳣

	//2.7get() ��������ָ���з��ص���ָ��
	//ע��õ���ָ�벻Ҫ�ͷ��ڴ�ռ䣬������ָ���Լ��ͷŸ��ã�������ͷ�2�γ���
	
	

	//2.11 ת����shared_ptr���ͣ�ת����ֵ
	shared_ptr<string>p13 = myFunction();

	
	system("pause");
	return 0;
}

/*
*(1)unique_ptr��ռʽָ��-�����ר������Ȩ
*ͬһʱ��������һ��unique_ptrָ��������󡣵�unique_ptr���ͷŵ�ʱ������ָ��Ķ���Ҳ�����١�
*	1.�����ʼ��
*	2.
*(2)unique_ptr���ò���
*	2.1unique_ptr��֧�ֵĲ���
*	2.2 �ƶ�����
*	2.3release(),������ָ��ָ�����Ŀ���Ȩ��������ָ�룬ͬʱ������ָ���ÿա�
*		���ص���ָ���������ʹ�á�
*	2.4reset()
*	�����������ͷ�����ָ�������ռ���ڴ�ռ䣬��������ָ���ÿ�
*	���������ͷ�ԭ�����ڴ�ռ䣬����ָ���¶���
*
*	2.5 =nullptr�ͷ�����ָ����ָ����ڴ�ռ䣬��������ָ���ÿ�
*
*	2.6ָ��һ������
	2.7get() ��������ָ���з��ص���ָ��
	
*	2.8������ *��ȡ����ָ��Ķ���ֱ�ӽ��в���
*	2.9swap()������������ָ����ָ��Ķ���
*	2.10����ָ��������Ϊif�ж�����
*
*	2.11 unique_ptrת����shared_ptr���ͣ�ת����ֵ
*	shared_ptr����һ����ʽ�Ĺ��캯����
*	ת���Ĺ����лᴴ�����ƿ�
*(3)
*
*	unique_ptr��û�п��ƿ��
*
*/