
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
	//�������캯��
	Human(const Human&TemHuman)
	{
		cout << "���ǿ������캯��ִ��" << endl;
		this->age = TemHuman.age;
		this->name = TemHuman.name;
	}
	Human&operator=(const Human&TemHuman)
	{
		this->age = TemHuman.age;
		this->name = TemHuman.name;
		
		return *this;
	}
};

class Man :public Human
{
public:
	Man();
	~Man()
	{
		cout << "man����������ִ��" << endl;
	}
public:

};

class Woman :public Human
{
public:
	Woman();
public:
	~Woman()
	{
		cout << "Woman��������ִ��" << endl;
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


class A
{
public:
	A(int value,string myStr):valueA(value),str(myStr)
	{
		;
	}
	private:
		int valueA;
		string str;
};

class B:public A
{
public:
	B(int i,string myStr,int j):A(i,myStr),valueB(j)//�������ഫ�ݲ���
	{
		;
	}
private:
	int valueB;
};



//3
class grandFather{};
class Father:public grandFather{};
class Son:public Father{};
//һЩ���ֱ�ӻ��࣬��ӻ���


class Base final	//��ʾ��Base������������Ļ���
{
	
};

int main(void)
{
	Man myMan1;
	/*���������������ɲ��֣�
	*(1)�������Լ�����ĳ�Ա��������Ա�������Ӷ���
	*(2)һ�����������̳еĻ�����Ӷ��󣬣������еĳ�Ա��������Ա�������������������л���ĳ�Ա���������ԣ���
	 */
	Human *p_human = new Man;//	Ϊʲô����ָ�����ʹ����������ʼ������-->����������л�����󲿷֡�
	//����������ĸ��࣬����͸���ת����������������������ʽ����ת����--->���������û��࣬���ǿ��Դ����������ʵ�Ρ�
	
	//2
	B b(12,"jisuanji" ,34);//����Ĺ��캯����ִ�У�Ȼ��ִ������Ĺ��캯��

	cout << sizeof(grandFather) << endl;	//1�ֽ�
	cout << sizeof(Father) << endl;//1�ֽ�
	cout << sizeof(Son) << endl;//1�ֽ�



	Human *p_human02 = new Man;
	Human&Human_reference = *p_human02;//�������ð󶨵������������
	/*p_human02��̬������Human����̬������Man
	 * 
	 */

	Man man03;
	Human human03(man03);//�������������ʼ��������󣬵��ÿ������캯����

	human03 = man03;//ֱ�ӵ������صĸ�ֵ�����
	
	system("pause");
	return 0;

}
/*
*(1)���������ģ�ͼ��
*���������⸸�ࡣ������ʽ�����ø�������ָ���������
*(2)������Ĺ��캯��
*	������ʵ����ʹ�û���Ĺ��캯������ʼ���������Ļ��ಿ�֡�
*	���๹�캯��ֻ��ʼ���Լ���������ݳ�Ա���Ӹ���̳е����ݳ�Ա���ø���Ĺ��캯����
*
*	��ô���ݲ��������๹�캯����
*		���캯����ʼ����Ա�б����ʽ��
*		���๹�캯��(�β��б�):��������(, , , ),�������г�Ա()
*(3)�ȿ��Ե����࣬�ֿ��Ե�����
*�̳й�ϵһֱ���ݣ�����һ���̳�����grandFather��Father��Son��
*
*(4)���뵱�������
*	����һЩ�಻��Ҫ��������ĸ��࣬c++11����final�ؼ��֣������������ʾ�಻�������ࡣ
*	final�����麯�������ʾ���ܱ����ء�
*(5)��̬�����붯̬����
*��̬���ͣ�������������ʱ�����ͣ���̬�����ʱ����֪�ġ�
*��̬���ͣ�ֻ����ָ�롢��������ʾ��ָ�򣩵��ڴ��еĶ������͡�
*��̬�����������е�ʱ�����֪����
*��̬���ͣ���̬�������ָ��ֻ�л���ָ�룬���ã��Ŵ������־�̬���ͺͶ�̬���Ͳ�һ�µ������
*������ǻ����ָ�룬���ã��Ͳ����ھ�̬���ͺͶ�̬���Ͳ�һ�µ������
*
*(6)��������������ʽ����ת��
*	��������ʽ��ִ�������ࣨ���ࣩ�������ʽ����ת����
*	����ת��֮�����ܹ��ɹ�������Ϊÿ�������඼����һ��������󲿷֣�
*	���Ի�������û���ָ���ǿ���ʹ����������ʼ����
*
*	��������ܶ�������Ҳ����Ϊ������һ���ִ��ڣ�Ҳ����Ϊ����������һ���ִ��ڡ�
*	�����ڴӻ��ൽ��������Զ�����ת����
*(7)���������֮��Ŀ�����ֵ
*	�����������Ϊһ����������ʼ�����߸�ֵʱ��ֻ�и����������Ļ��ಿ�ֱ��������߸�ֵ��
*	���������еĲ��ֲ��ḳֵ��
*	Ҳ����˵������ֻ�ɻ����Լ������顣��������鲻��ȥ�������⣺(1)Ϊʲô������1���ֽڣ�
*
*/



