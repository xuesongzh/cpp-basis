
#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;

class  Human
{
private:
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
	//��Ԫ����
	friend  void myFriendFunction01(const Human&temHuman) ;	//�������������Human����Ԫ����
};


//��Ԫ������ʵ��
void myFriendFunction01(const Human&temHuman)
{
	cout << "����Human�����Ԫ����" << endl;
	cout << temHuman.age << endl;//��Ԫ�������Է���private��Ա
	
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



int main(void)
{
	Human h1 = Human(12, "jisuanji");
	myFriendFunction01(h1);

	
	system("pause");
	return 0;

}
/*
*(1)��ͨ����������Ԫ������
*3�ַ���Ȩ�ޣ�public,protected,private.
*ֻҪ�ú�����Ϊ�����Ԫ�������Ϳ��Է���������г�Ա��������Ա�����ͳ�Ա������public ,protected private����������
*
*	�����ڲ�������Ԫ������ʹ�� friend ��������
*	�����ⲿ������Ԫ����
*	1.һ��Ҫ�������Ա��Ϊ������������Ϊֻ�������ſ��Է��ʳ�Ա���Ժͳ�Ա������
*
*	2019��11��20��16:45:35
*	 Sunrise�ڶ���������ѧ�ڶ���ѧ¥1121ʵ����
*/



