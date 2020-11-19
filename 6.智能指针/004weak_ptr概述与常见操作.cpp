#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include <memory>

using namespace std;


int main(void)
{
	//weak_ptrһ����ʹ��shared_ptr��������Ů
	auto p1 = make_shared < int>(100);
	weak_ptr<int>p2Weak(p1);//p2Weak�������ã�ǿ���ü�������ı䣬һ��ǿ���ã�һ��������ָ��100
	//ֻ��ǿ���þ�������������ڡ������öԶ���������û��Ӱ��
	weak_ptr<int>p3Weak = p2Weak;//ʹ��һ�������ø���һ�������ø�ֵ��

	//lock()�Ĺ��ܣ����weak_ptr��ָ��Ķ����Ƿ���ڣ�������ڣ��ͷ���һ��ָ��ö����shared_ptrָ�룬
	//���������,���ص�ָ��ָ��Ϊ��
	//p1.reset();//�ͷŸö���
	auto p4shared_ptr = p2Weak.lock();//p4shared_ptr��һ�����ص�shred_ptr,ǿ���ü���+1
	

	//���������÷�
	int count = p2Weak.use_count();
	cout << count << endl;	//2

	//expired--�����ж�
	//ָ��100������ǿ���ö�����Ϊ����
	p1.reset();
	p4shared_ptr.reset();
	if (p2Weak.expired())//����ֵΪtrue
	{
		cout << "�����Ѿ�����" << endl;
	}

	//(4)�ߴ�����
	weak_ptr<int>p5_weak;
	int*p6 = nullptr;
	int length1 = sizeof(p5_weak);	//8
	int length2 = sizeof(p6);	//4
	cout << "length1=" << length1 << endl;
	cout << "length2=" << length2 << endl;

	system("pause");
	return 0;
}

/*
*(1)weak_ptr����
*���ڸ���shared_ptrָ����й���
*ǿָ��strong--shared_ptr
*��ָ��weak--weak_ptr
*weak_ptrҲ��һ����ģ�壬���ָ��ָ��һ����shared_ptr����Ķ��󣬵���weak_ptr�������������ڡ�
*���仰˵����weak_ptr�󶨵�shared_ptr�ϲ���ı�shared_ptr��������ü�����
*��shared_ptr��Ҫ�ͷ���ָ������ʱ�򣬲����Ƿ���weak_ptr�Ƿ�ָ��ö���
*
*weak_ptrΪʲô��Ҫ���룿����
*weak--��������Ҳ�������ã�������
*���ã����Ϊ����shared_ptr���������ڣ��Ƕ�shared_ptr��һ�����䡣
*weak_ptr����һ�ֶ���������ָ�룬��������������ָ�����Դ����������������shared_ptr��һ������
*weak_ptr���ڼ�������ָ��Ķ����Ƿ���ڡ�
*
*
*(2)weak_ptr�Ĵ�����
*ʹ��shared_ptr��ʼ��weak_ptr
*
*(3)weak_ptr�÷�
*	����ʹ��weak_ptrΪshared_ptr��ֵ
*	
*	1.use_count() ��ȡ����ָ�빲����������shared_ptr������������˵��ȡ��ǰ�۲�֧Ԯ��ǿ����������
*	2.expired()�Ƿ���ڵ���˼��������ָ���use_count()==0������true�����仰˵��������������ж����۲����Դ�Ƿ��Ѿ����ͷš�
*(4)�ߴ�����
*	weak_ptr<int>pw
*	weak_+ptr��shared_ptr�ߴ�һ��������ָ�������
*	һ������ָ���������ָ�룬��1����һ��ָ��ָ������ָ��Ķ���
*		��2���ڶ���ָ��ָ������ָ����ƿ顱�����ݽṹ�����ƿ������С�ǿ���ü��������������ü��������������ݵ����ڴ���������Զ���ɾ�����ȡ�
*	��ϸ��ͼ
*		
*
*2019��11��27��17:07:39
* Sunrise�ڶ���������ѧ�ڶ���ѧ¥1121ʵ����
*/