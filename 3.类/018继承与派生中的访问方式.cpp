
#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;

class Human
{
private:
	
public:
	//���캯��
	Human();
	Human(int m_i,string str,int myProtected,int myPrivate);

	//��������
	~Human();
	
public:
	int age;	//����
	string str;	//����
	void myPubFunction() { ; }

public:	//�����ͬ���������ɺ�������
	void myFunction();
	void myFunction(int tem);
protected:	//ֻ��������ĳ�Ա�����е���
	int myProtected;	//���������ĳ�Ա�������Է���
	void myProFunction() { ; }
private://���඼���ܷ���
	int myPrivate;
	void myPriFunction() { ; }
};

//���캯��
Human::Human()
{
	cout << "ִ����HumanĬ�Ϲ��캯��" << endl;
}

Human::Human(int age, string str,int myWeath,int myPrivete)
{
	this->age = age;
	this->str = str;
	this->myProtected = myWeath;
	this->myPrivate = myPrivete;
	
	cout << "ִ����Human�������Ĺ��캯��" << endl;
}

//��������
Human::~Human()
{
	cout << "ִ����Human��������" << endl;
}

void Human::myFunction()
{
	cout << "myFunction" << endl;
}

void Human::myFunction(int tem)
{
	cout << "myFunction" << tem << endl;

}


class Man:public Human	//������̳���Human��
{
public:
	Man();
	void myFunction(int tem);
public:
	using Human::myFunction;	//vs2015�����֧�ֲ�̫��
};

void Man::myFunction(int tem)
{
	Human::myFunction(3);
	Human::myFunction();
	cout << "myFunction man" << tem << endl;
}




Man::Man()
{
	cout << "ִ����man���Ĭ�Ϲ��캯��" << endl;
}



int main(void)
{
	Man m1;	//�ȵ��ø���Ĺ��캯����Ȼ���������Ĺ��캯��
	m1.age = 12;
	m1.str = "��Ǭ��";

	m1.myPubFunction();	//������Ե��ø����public��Ա����,


	//�������͸�����ͬ����������ô�������ֻ�ܵ�������ĺ��������ܵ��ø�������صĺ���
	m1.myFunction(123);
	/*���ȷʵ����ø���ĳ�Ա������1.������ĳ�Ա�����У�����ʹ�� �������֣���ͬ�������� ǿ�Ƶ��ø��ຯ��
	 *2.using using namespace
	 *c++11�У��ø���ͬ�������������пɼ�
	 *ͨ��using����ؼ��֣��ø����ͬ�������������пɼ���˵���˾����ø���ͬ�������������������صķ�ʽʵ�֡�
	 *
	 */

	m1.myFunction();	//����ø����myFunction����
	system("pause");
	return 0;

}



/*
 * (1)������ĸ���
 *	��֮����һ�ֲ�ι�ϵ���и����к�����
 *	�������и��ࣨ���࣬���ࣩ�������������γ������ǽк����ࡣ���࣬�����ࣩ
 *	�и�������ࡣ�����˲�ι�ϵ���м̳С�������ԴӸ�������̳кܶණ����
 *	�̳еĸ�����������������Ƶĺ���˼��֮һ��
 *
 *	ʵ�ּ̳У�
 *		1.����һ�����࣬����һЩ���õĳ�Ա��������Ա����
 *		2.ͨ���̳и����������µ��ࣺ���ࡣд����ʱ������ֻ��Ҫд��������ص�һЩ���ݼ��ɡ�
 *		3.����̳��Ը��࣬����������ĸ��࣬�����������������ʼ�������������һ��ȸ���ӵ�и���Ĺ��ܡ�
 * (2)�̳з�ʽ����public private protected,�̳��� class ��������:public/private/protected ����
 * 
 * (3)��������ù��캯����˳��
 *	�ȵ��ø���Ĺ��캯������ʼ������ĳ�Ա������Ȼ���������Ĺ��캯������ʼ������ĳ�Ա������
 * (4)���Ա�����ͳ�Ա���Ե�3�з���Ȩ�� �� 3�м̳з�ʽ
 *	public�����Ա�����ʵ�����
 *	private��ֻ������ĳ�Ա��������
 *	protected��ֻ�������������ĳ�Ա��Ա�������ʡ�
 *
 *	���������ʹ��public��ʽ�̳�
 *	����			����			�����������
 *	public		public		public
 *	protected	public		protected	//��Ҫ
 *	private		public		�޷���Ȩ��
 *
 *	public		protected	protected
 *	protected	protected	protected
 *	private		protected	�޷���Ȩ��
 *
 *
 *	public		private		private
 *	protected	private		private
 *	private		private		�޷���Ȩ��
 *
 *ע�⣺
 *	1.����public�̳в��ı丸��ķ���Ȩ��
 *	2.protected�̳н������е�public��Ա��Ϊ�����protected��Ա��
 *	3.private�̳�ʹ�ĸ������г�Ա�������б�Ϊprivate
 *	4.�����private��Ա���ܼ̳з�ʽ��Ӱ�죬������Զ�޷�����
 *	5.���ڸ��������������Ǹ���ĳ�Ա����������㲻�����ⲿ���ʣ�������Ϊprivate��
 *		���������������ʣ�������Ϊprotected��
 *		����빫����������Ϊpublic��
 *	
 *(5)�����ڱ�
 *	���������Ե��ø����public��protected���������ǵ���ͬ������ʱ�����ຯ������ͻ����θ����ͬ������
 *
 *	using Human::myFunction;
 *	����ֻ���ƶ������������ǻ����е�public protected������ͬ��������myFucntion���������ж��ɼ���
 *		������һ����ͬ�������������пɼ���ֻ��ȫ���ɼ���
 *	using�������ҪĿ��������ʵ���������е��ø����ͬ���������������еĲ�������������˳��͸����е�ͬ����������
 *	���ɺ������ص�ʱ��������ֿ���
 *	 Sunrise�ڶ���������ѧ�ڶ���ѧ¥1121ʵ����
 *	 2019��11��19��10:39:17
 *	 
 *	
 */