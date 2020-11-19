#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;

class  Human
{
public:
	int age;
	string name;
public:
	//���캯��
	Human();
	Human(int age, string name);
	//��������
	~Human()
	{
		cout << "Human��������" << endl;
	}
public:
	void myFunction();
	//virtual void eat() final;
	virtual void eat()//�麯����ʵ��	����ʱ��̬ʶ��
	{
		cout << "����Human��eat����" << endl;
	}
};

class Man:public Human
{
public:
	Man();
public:
	void myFunction();
	void eat() override;
	
};
void Man::eat()
{
	cout << "man�е�eat��������ִ��" << endl;
}


class Woman:public Human
{
public:
	Woman();
public:
	void myFunction();
	void eat() override
	{
		cout << "woman�е�eat()����" << endl;
	}
};


void Human::myFunction()
{
	cout << "Human���еĺ���ִ��" << endl;
}

void Man::myFunction()
{
	cout << "Man���е�myFunction����ִ��" << endl;
}


Human::Human()
{
	cout << "HumanĬ�Ϲ��캯��" << endl;
}

Human::Human(int age, string name)
{
	this->age = age;
	this->name = name;
	
}

Woman::Woman()
{
	cout << "woman�Ĺ��캯��" << endl;
}

void Woman::myFunction()
{
	cout << "Woman���е�myFunction����" << endl;
}



Man::Man()
{
	cout << "Man���Ĭ�Ϲ��캯��" << endl;
}



int main(void)
{
	Human*p_human = new Human;
	Man *p_man = new Man;

	//����������ĸ��࣬����ָ�����newһ���������
	Human*p_human2 = new Man;	//ok��ʹ����������ʼ������ָ��
	Human*p_human3 = new Woman;
	
	p_human2->myFunction();	//������ø����еĺ���
	//���Ǹ���ָ��ʵ������ָ������Ķ���������������ĺ�����--->������
	//---����ָ��ָ����������������͵��ö�Ӧ�ĺ���--->��̬
	p_human->eat();	//���ø���eat()
	p_human2->eat();//����Man��eat()
	p_human3->eat();//����Woman�еĺ���eat()
	p_human3->Human::eat();//��ʽ���ø����eat()����

	
	delete p_human;
	delete p_human2;
	delete p_human3;
	/*
	 *���ǵ���Human����������,��������ø����������������Ӧ����ô�죿
	 *
	 */
	system("pause");
	return 0;

}
/*(1)����ָ�룬������ָ��
 *	ʹ��new���������Ƿ���ָ��
 *	����ָ��ʹ����������ʼ��������ֻ�ܵ��ø����е�ͬ������---->��ε�������ͬ������--->������--->�麯��-->��̬
 *
 *
 *ʵ���е������Ĳ����Ǹ���ָ�룬���Խ������е����������Ϊʵ�δ��ݹ�����ʵ�ֶ�̬����ʶ�������ø���������е�ͬ��������
 *(2)�麯��--ʵ�ֶ�̬
 *	�����ͬ������ǰ������virtual.����ʾ����һ���麯��������ʵ�ֶ�̬�������ͬ���������Բ�дvirtual���Զ�Ϊ�麯����
 *	���ຯ�������ຯ�������֣��������������ͣ�������ȫ��ͬ���Ż��ж�̬��
 *
 *	����--��һ�����ڲ�����������ͬ�����ǲ����������������ͣ�����˳��ͬ������ʱ��ʹ�ò���������
 *	��д���麯��ʵ�ֶ�̬�������е�ͬ�������������к������֣����������ܸı䡣
 *	�ض��壺�̳�����������д������������ı��˲������������ͣ�����˳��ȡ�
 *
 *Ϊ�˱�������������д���麯������c++�У�������ں�������������һ��override�Ĺؼ��֡�����ؼ������ڡ����ࡱ�У�
 *	���븸�����麯�����ſ��Լ���override������ᱨ�����������ܸ��ǵ�ʱ��Ҳ�ᱨ��
 *	override��������˵���������е��麯�����������ͻ���Ϊ�����eat()���������˸����е�ͬ��������
 *	�������ͻ��ڸ�������ͬ��ͬ�������麯�������û�ҵ����ͻᱨ��
 *
 *(3)final�ؼ���
 *	����overrode��Եģ�Ҳ�������麯���У�ʹ���ڡ����ࡱ�У���������ڸ���ĺ����������ˡ�final���ؼ��֣���ô�κγ���
 *	���Ǹú����Ĳ���������������
 *
 *	��̬�󶨣���̬��ʾ�ľ������ǵĳ������е�ʱ���֪������ָ��ָ���ĸ����󣬵��ö���Ķ�Ӧ�ĺ�����
 *	���е�ʱ���֪���ĸ�����󶨵�eat()�����С�
 *(4)��̬��
 *	��̬��������麯����˵�ġ�
 *	�����ھ��м̳й�ϵ�ĸ��������֮�䣬������д�˸����Ա����virtual��ͨ�������ָ�룬ֻ�е��˳�������ʱ���ҵ�����̬�󶨵�
 *	����ָ��ĺ�����Ȼ��ϵͳ�ڲ���ѯ�麯����ִ�ж�Ӧ�ĺ����������������麯������
 *
 *
 *(6)
 * 
 */


