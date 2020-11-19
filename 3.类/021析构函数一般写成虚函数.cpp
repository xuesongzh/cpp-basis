
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
	virtual ~Human()
	{
		cout << "Human��������" << endl;
	}
public:
	virtual  void eat() = 0;
};

class Man :public Human
{
public:
	Man();
	virtual void eat() override;
public:
	~Man()
	{
		cout << "ִ����Man����������" << endl;
	}

};

class Woman :public Human
{
public:
	Woman();
	virtual void eat() override;
public:
	~Woman()
	{
		cout << "ִ����Woman����������" << endl;
	}

};

Woman::Woman()
{
	cout << "����woman�Ĺ��캯��" << endl;
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

Man::Man()
{
	cout << "Man���Ĭ�Ϲ��캯��" << endl;
}



void Woman::eat()
{
	cout << "Woman���eat()ִ��" << endl;
}
void Man::eat()
{
	cout << "Man���eat()ִ��" << endl;
}


void playObject()
{
	Human *p_human01 = new Woman;
	p_human01->eat();//����Woman��eat()����

	Human*p_human02 = new Man;
	p_human02->eat();//����Man��eat()����

	//ִ����ȷ����ִ�и��๹������๹�� ��������������������
	Woman *p_woman = new Woman;
	delete p_woman;
	
	//����ִֻ�и��������������û��ִ���������������
	cout << "-------------------------------------" << endl;
	delete p_human01;
	delete p_human02;
	/*
	ִ����Woman����������
	Human��������
	ִ����Man����������
	Human��������
	 */
}

int main(void)
{
	playObject();


	system("pause");
	return 0;

}
/*(1)�û���ָ��ָ������Ķ��󣬵�deleteֻ���ø������������������ִ���������������
 *����취��
 *	�Ѹ����е���������д���麯����
 *
 *	�ܽ᣺
 *		1.һ�����඼��public�̳С���public�̳��У�������������������Ĳ�����ֻ��Ӱ�쵽�ӻ���̳������ĳ�Ա��
 *			�����Ҫ��������Ի���Ǽ̳г�Ա�������в�������Ҫ�������Ա��������Ϊ�麯������������Ҳ����ˡ�
 *		2.�����������������麯������Ҳ��̳и����࣬�������������������ȻҲ���麯������Ȼ��������������͸����
 *			�����������ֲ�ͬ���������Ƕ��Ǽ̳е��麯����
 *		3.deleteɾ��һ��ָ���������ĸ���ָ���ʱ�򣬿϶�Ҫ���ø������������������������������е��ø��������������
 *			���Ը��������������Ҫ����Ϊ�麯����Ҳ����˵��c++Ϊ�˻������ʱ�Ķ�̬�������õĳ�Ա����������Virtual���͵ġ�
 *
 *		4.���ۣ����һ��������������࣬��ذ������������д��virtual���ͣ�ֻҪ����������������麯�������ܱ�֤����delete
 *		����ָ���ʱ�������ȷ�����������汾���ȵ������࣬�ٵ��ø��ࣩ
 *
 *		�麯���������ڴ濪���������涨���麯�����������ͻ������������麯����������������麯����ָ�롣
 *
 *
 *������Ϣ��
 *	�����ǰ��������߹��캯����д�����ڲ�ʵ�֣����ܸ���Ϊ��������������f11���뺯���ڲ�ִ�С������ں���������һ���ϵ㡣
 *	��ǰ��˵��û��ִ�������Լ���д�Ĺ�����������Ǵ���ģ�
 *	2019��11��19��17:44:50
 *	 Sunrise�ڶ���������ѧ�ڶ���ѧ¥1121ʵ����
*
*/



