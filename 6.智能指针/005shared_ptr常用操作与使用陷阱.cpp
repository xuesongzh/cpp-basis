#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include <memory>

using namespace std;

//������
class CT:public enable_shared_from_this<CT>
{
public:
	shared_ptr<CT>getself()
	{
		//return shared_ptr<CT>(this);
		return shared_from_this();//enable_shared_from_this���еķ���
	}
};

class B;//����B��
class A
{
public:
	
	shared_ptr<B> pm_b;
	//����취��
	//weak_ptr<B>pm_b''
	~A()
	{
		cout << "A����������" << endl;
	}
};


class B
{
public:
	shared_ptr<A> pm_a;
	~B()
	{
		cout << "B����������" << endl;
	}
};
//A���B��ѭ������

shared_ptr<int>createFunction(int value)
{
	return make_shared<int>(value);//����һ��shared_ptrָ��
}
//
//void myFunction(int value)
//{
//	shared_ptr<int>pTem = createFunction(100);
//	return;//�뿪�������pTem��ָ����ڴ�ᱻ�Զ��ͷ�
//}


shared_ptr<int> myFunction(int value)
{
	shared_ptr<int>pTem = createFunction(100);
	return pTem;//���ؾֲ�����
}


void myFuncion02(shared_ptr<int>ptr)
{
	return;
}

int main(void)
{
	//(1)
	myFunction(100);
	shared_ptr<int>p1 = myFunction(10);//������ñ��������ܣ����صľֲ������ͻ����١�


	//2.1������ָ��
	int*p = new int(100);
	//myFuncion02(p);//error,��������ʽ����ת��
	myFuncion02(shared_ptr<int>(p));//��������ʱ��shared_ptr����һ����ָ����ʽ�Ĺ���
	*p = 22;//��һ���ڴ��Ѿ������գ���ʱ���󴫵ݸ��������Ǹ��ֲ���������������ϻ��ͷš�
	//�ڴ����Ĺ����Ѿ���������ָ�룬���ﲻҪ��ʹ����ָ��

	//��Ҫʹ����ָ���ʼ�����shared_ptr--�ᵼ���ڴ��ͷŶ�� p3,p4�޹�
	/*int*p2 = new int(200);
	shared_ptr<int>p3(p2);
	shared_ptr<int>p4(p2);*/
	//���ķ�����
	shared_ptr<int>p3(new int(200));
	shared_ptr<int>p4(p3);//����д����ok�ģ��õ���ͬһ�����ƿ飬ָ��ͬһ���ڴ��
	
	//2.2����get()�����ķ���ֵ--����ָ������ָ�����ָ�룬����ɾ��
	shared_ptr<int>p5(new int(234));
	int *p6 = p5.get();
	//delete p;
	//�����Խ���������ָ��󶨵�get���ص���ָ����
	//shared_ptr<int>p7(p6);//��������ָ��û�й�ϵ����һ���ͷŵ�ʱ����һ�����ͷ�һ�ξͻ����
	//ÿ������ָ������ָ�봴��������֮����������໥����ġ�

	//3.��Ҫ�������ָ�루this����Ϊshared_ptr���أ�����enable_shared_from_this����
	shared_ptr<CT>Pct1(new CT);
	//shared_ptr<CT>Pct2(Pct1);//����ǿ����,ʹ��ͬһ�����ƿ�
	shared_ptr<CT>pct3 = Pct1->getself();//��������ָ��֮�䲻��ʹ��ͬһ�����ƿ飬û�й�ϵ.��һ��ʹ����ָ���ʼ������ָ���
	//����취��c++��׼���е���ģ��enalbe_shared_from_this�����ص���һ������ָ��


	//2.4����ѭ������
	shared_ptr<A> pca(new A);
	shared_ptr<B> pcb(new B);
	pca->pm_b = pcb;//ָ��pcb��������ǿ����
	pcb->pm_a = pca;//ָ��pca��������ǿ����
	/*
	 * �������е��ڴ涼û���ͷţ���Ϊ�������������ÿ�������ǿ���ö���2���������ͷš�
	 * ����취��
	 *	ֻ��Ҫ������һ����Ϊ�����ü��ɡ�
	 */

	//3.2�ƶ�����
	shared_ptr<int>p7(new int(1000));
	shared_ptr<int>p8(std::move(p1));//�ƶ����죬�ƶ�����һ���µ�����ָ�����p8,p7����ָ��1000��
	//���ü�������1

	//43.����ʹ��make_shared�����������Ż����������
	shared_ptr<string>p9(new string("jisuan"));
	/*
	 * ���������ڴ棬һ�δ洢jisuan��һ���������p9�Ŀ��ƿ�
	 */
	auto p10 = make_shared<string>("jisuajis");//ֻ����һ���ڴ�
	system("pause");
	return 0;
}

/*
*(1)shared_ptrʹ�ó���-
*	�Ӻ�����return shared_ptr����ָ��
*	
*
*(2)����ָ�����ô������
*	2.1������ָ��--ʹ����ָ�븳ֵ������ָ����ڴ��������ξͽ�������ָ�룬�Ͳ�Ӧ����ʹ����ָ������ڴ��ˡ�
*		����ʹ����ָ���ʼ�����shared_ptr
*	2.2����get()�����ķ���ֵ
*	�������ܶ������ָ�벻��delete��������쳣
*	��Զ��Ҫ��get()�õ�����ָ������ʼ����һ������ָ�롣
*	3.��Ҫ�������ָ�루this����Ϊshared_ptr���أ�����enable_shared_from_this����
*		���ض����thisָ�룬ʹ��public�̳�enable_shared_from_this<>��Ȼ�󷵻�shared_from_this()
*	ԭ��enable_shared_from_this����һ����ָ��weak_ptr,ͨ�������ָ�����thisָ�롣
*	�����ǵ���shared_from_this()������ʱ����������ڲ�������weak_ptr��lock()����������shared_ptrָ�������+1
*	������shared_ptrָ��
*	2.4����ѭ������
*		
*(3)����˵��
*3.1�ߴ�����
*	shared_ptr��weak_ptr�ĳߴ綼����ָ���2����
*	�������ƿ��ʱ����
*	1.make_shared,���䲢��ʼ��һ�����󣬷���ָ��˶����shared_ptr
*	2.����ָ����������Ůһ��shared_ptr����ʱ��ʹ����ָ������������ƿ飬���2.2
*	
*3.2�ƶ�����
*�ƶ��϶��ȸ�ֵ�飬����Ҫ�������ü����������ƶ������������ü�����
*
*(4)����˵����ʹ�ý���
*	1.������������û�н��⡣
*	2.����ָ��Ҳ���ǿ�������������ʹ�ã�����ʹ�á�
*	3.����ʹ��make_shared�����������Ż����������
*
*/