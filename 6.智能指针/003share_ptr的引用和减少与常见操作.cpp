#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include <memory>

using namespace std;

class A
{
public:
	A()
	{}
	~A()
	{
		
	}
};

//void myfunction(shared_ptr<int>&myp)//ʹ�����ã����ü�����������
void myfunction(shared_ptr<int>myp)
{
	cout << "����ָ�����������������ü�������" << endl;
}

shared_ptr<int> myfunction02(shared_ptr<int>&myp)
{
	cout << "����ָ������������ֵ�����ü�������" << endl;
	return  myp;
}


void mydelete(int*p)//�Լ�ָ����ɾ����
{
	cout << "���������Լ������ɾ����" << endl;
	//......
	delete p;
}

//3.����ģ���װ
template<typename T>
shared_ptr<T>make_shared_array(size_t size)
{
	return shared_ptr<T>(new T[size], default_delete<T[]>());
}


int main(void)
{
	//1�����ü���������
	auto p1 = make_shared<int>(100);//int =100����ֻ��һ�������ߣ�p1
	auto p2(p1);//����������p1,p2		2 strong refs
	myfunction(p2);//������ָ�뵱������ʵ�δ��ݸ����� --���ü�������1
	//��Ϊ����ʵ�δ��ݣ�����������
	auto p3 = myfunction02(p2);


	//2���ü����ļ���
	auto p4 = make_shared<int>(400);//p4ָ���¶���p4���ü���Ϊ1
	p1 = make_shared<int>(500);//p1���ü�������Ϊ1

		//3.��һ��shared_ptr���͵�ָ���1��Ϊ0�������Զ��ͷ��Լ�������ָ�򣩵Ķ���
	auto p5 = make_shared<int>(1000);
	auto p6 = make_shared<int>(1000);
	p6 = p5;//�����Ǹ�ֵ��p6�����ü�����Ϊ2�� p5���ü�����Ϊ2��


	//shared_ptr�����ж��ٸ�����ָ��ָ��ĳ������
	int myCount = p6.use_count();
	cout << myCount << endl;	//2
	int myCount02 = p5.use_count();
	cout << myCount02 << endl;	//2

	//2.unique(*)�Ƿ������ָ���ռָ��ĳ�����󣬷���true����false
	shared_ptr<int> p7(new int(7));
	if (p7.unique())
	{
		cout << "unique������ֻ��p7ָ��һ���ڴ����" << endl;
	}

	//reset������������λ���ÿ�
	shared_ptr<int> p8(new int(8));
	auto p9(p8);
	p8.reset();
	if (p8==nullptr)
	{
		cout << "p8ָ��Ϊ��" << endl;
	}
	//reset������newһ���¶���
	shared_ptr<int> p10(new int(10));
	p10.reset(new int(11));//�ͷ�ԭ���ڴ棬ָ���µ��ڴ�

	//��ָ��Ҳ����ʹ��reset���³�ʼ��
	shared_ptr<int>p11;
	p1.reset(new int(11));
	
	//4������
	shared_ptr<int>p12(new int(12));
	cout << *p12 << endl;
	
	//get()����ָ��
	shared_ptr<int>p13(new int(13));
	int*p14 = p13.get();
	cout << *p14 << endl;
	//���ﲻҪ�ֹ��ͷ�p14����ָ����ڴ�ռ������ָ��p13����

	//swap()
	shared_ptr<string> p15(new string("aaaa"));
	shared_ptr<string> p16(new string("bbbb"));
	swap(p15, p16);
	cout << *p15 << endl;//bbbb
	cout << *p16 << endl;//aaaa

	//=nullptr
	p15 = nullptr;

	//����ָ��������Ϊ�ж�����
	if (p16)
	{
		cout << "p16ָ��һ������" << endl;
		p16 = nullptr;
		
	}

	//ָ���Զ������ɾ����
	shared_ptr<int>p17(new int(17), mydelete);
	p17 = nullptr;//�����Լ�д��ɾ����,�Լ���Ҫ�ں�����������ڴ���ͷ�
	//ɾ����������һ��lambda���ʽ
	shared_ptr<int>p18(new int(18), [](int*p) {delete p; });


	//��Щ����£�Ĭ��ɾ����������---��̬����
	shared_ptr<int>p19(new int[10], [](int*p) {delete[]p; });

	//����ʹ��default_delete����ɾ������default_delete�Ǳ�׼�������ģ����
	shared_ptr<A>pA(new A[10], std::default_delete<A[]>());//����[]��ʾ��ɾ����һ������

	//c++17  ���������ʱ����<>�����[]

	//shared_ptr<A[]>pA2(new A[10]);//����c++17������������������ͷ�����


	//shared_ptrģ���װ
	shared_ptr<int>p20 = make_shared_array<int>(5);
	
	system("pause");
	return 0;
}

/*
*(1)shared_ptr���ü��������Ӻͼ���
*����ʽָ��--���ü���--ÿһ��shared_ptr��ָ����ͬ���ڴ棬���һ��ָ�븺���ͷš�
*	1.���ü���������
*	ÿ��shared_ptr�����¼�ж���������shared_ptrָ��ָ����ͬ�Ķ���
*	����������£�����ָ��������ֵ�shared_ptr���ü�����������1��
*		ʹ��һ��ָ���ʼ����һ��ָ��
*		������ָ�뵱������ʵ�δ��ݸ�������ʹ�����ã����ü����������ӣ�
*		��Ϊ��������ֵ
*	2.���ü����ļ���
*		1.��shared_ptr�����µ�ֵ����shared_ptrָ��һ���µĶ���
*		2.�ֲ���shared_ptr�뿪����
*		3.��һ��shared_ptr���͵�ָ���1��Ϊ0�������Զ��ͷ��Լ�������ָ�򣩵Ķ���
*		
*(2)shared_ptr����ָ��ĳ��ò���
*	1.shared_ptr�����ж��ٸ�����ָ��ָ��ĳ������
*	2.unique(*)�Ƿ������ָ���ռָ��ĳ�����󣬷���true����false
*	3.reset()��λ���ָ�������
*		reset()������������ôָ����Ψһָ���ָ�룬��ô�ͷ�ָ����ڴ�ռ䣬����ָ���ÿ�
*				������ָ��ö����Ψһָ�룬��ô���øö�������ü�������٣�ͬʱ��ָ���ÿա�
*		reset()������������һ����new������ָ�룬
*			��ָ����Ψһָ�룬���ͷ�ָ��ָ��Ķ�����ָ��ָ���¶���
*			��ָ�벻��Ψһָ�룬���ͷ�ָ�룬���ü�������1��ָ���¶���
*	4.�����ã�ʹ��*����ָ��ָ�������
*	5.get����p�б����ָ�룬�������ָ���ͷ�����ָ��Ķ��󣬷��ص���ָ��Ҳ��û�����塣
*		��Ϊ��Щ��������ĺ����������е���Ҫһ����ָ�룬����������ָ��
*	6.swap()������������ָ����ָ��Ķ���
*	7.=nullptrָ���
*		1.��ָ������ü�������1�������ü�������Ϊ0�����ͷ�ָ��ָ��Ķ���
*		2.������ָ���ÿ�
*	8.����ָ��������Ϊ�ж�����
*	9.ָ��ɾ��������������
*		һ��ʱ��������ָ����������ɾ����ָ��Ķ��󣬽�delete�������ΪĬ�ϵ���Դ������ʽ��
*		����������Լ������󣬿���ָ���Լ���ɾ����ȡ��ϵͳ�ṩ��Ĭ��ɾ������
*		shared_ptr�ڲ�������Ӿ����ɾ�����������ּ��ɡ�
*
*	ָ��ɾ��������˵����
*		******��������share_ptrָ���˲�ͬ��ɾ����������ֻҪ����ִ�еĶ���������ͬ��������share_ptr����ָ�����ͬһ�����͡�
*			������ͬ���ʹ�����Էŵ�Ԫ������Ϊ�ö������͵�����������
*			
*		make_shared���ᳫ�ķ��������ǲ��������Լ���ɾ������
*(3)����ģ������װshared_ptr����
*
*
*���������ü��������ڵ�ָ���ǿ���á�
*
*2019��11��27��13:19:27
* Sunrise�ڶ���������ѧ�ڶ���ѧ¥1121ʵ����

*/