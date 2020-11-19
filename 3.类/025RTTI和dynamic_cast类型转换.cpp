#include<iostream>
#include<cstdlib>
#include<string>

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

	virtual void eat()
	{
		cout << "Human eat()����" << endl;
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
	virtual void eat()
	{
		cout << "Man eat()����" << endl;
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

	virtual void eat()
	{
		cout << "woman eat()����" << endl;
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


int main(void)
{
	//(1)����ʱ����ʶ��
	Human *p_human = new Man;
	Human&q = *p_human;//*p_human��ʾָ����ָ��Ķ���
	q.age = 12;
	q.name = "jisuanji";
	q.eat();

	//��ô������ָ��ת��Ϊ�������
	Man *m1 = (Man*)(p_human);//c����ǿ������ת�������Գɹ�--����Ҫ����ȷ֪����ʲô���ͲŰ�ȫ�����򲻰�ȫ
	m1->eat();//����Man�е�eat()����
	Woman *w1 = (Woman*)p_human;	//ת��Ϊ��������Ҳ�ɹ�������ȫ
	
	//dynamic_cast���԰�����������ȫ���
	Man*m2 = dynamic_cast<Man*>(p_human);	//ǿ����ָ��ת��Ϊ��������ָ��
	m2->eat();//ִ��man���eat()����
	//�������ã������dynamic_castת��ʧ�ܣ�ϵͳ���׳�һ��std::bad_cast�쳣��
	Human&m_reference = *p_human;
	try
	{
		Man m3 = dynamic_cast<Man&>(m_reference);	//�ɹ�
		//(2)typeid�����
		cout << typeid(m_reference).name() << endl;	//class Man
		cout << typeid(m3).name() << endl;		//class Man
		
	}

	catch (std::bad_cast)
	{
		cout << "std::bad_cast" << endl;
	}

	Human h1 = Human(12, "jisuanjiii");
	cout << typeid(h1).name() << endl;	//class Human
	int a = 10;
	cout << typeid(a).name() << endl;	//int
	cout << typeid("jisuanjizuchengyuanli").name() << endl;	//char const [22]


	//1.����ָ�붨���������ͬ
	Human*p_human02 = new Woman;
	if (typeid(p_human)==typeid(p_human02))
	{
		cout << "p_human��p_human02��ͬһ��ָ������" << endl;	//������������Ԥ�ϵĲ�ͬ
		/*�Ƚϵ�ʱ���ǱȽϵĶ�������ͣ�������new����������ͣ���Ҳ������֤ǰ���RTTI����ʶ��
		 */	
	}

	//���������Ƚ�new�����Ķ����ʵ�����ͽ��бȽϣ�����ô����
	Woman*p_woman = new Woman;
	Human*p_human03 = p_woman;	//
	/*
	 * p_woman����������һ�����ǿ�������ָ�룬ָ�������������������Woman���麯����
	 * �麯����ĵ�һ����type_info()�����ȷ��P-womanָ����һ������ȥ���ö�Ӧ���麯����
	 */
	if (typeid(*p_human)==typeid(*p_human03))//��������ʵ��ָ��Ķ������ͱȽ�
	{
		cout << "p_human��p_human03����������ͬ" << endl;

	}
	/*	�����б������麯���������ϱ�����������
	 * �ܽ᣺�Ƚϵ�ʱ��Ҫʹ��typeid(*ָ��)����ʵ�ʶ���ıȽϣ�����Ҫ���ж���ָ�����͵ıȽϡ�
	 * �мǣ�ֻ�е����������麯����ʱ�򣬱������Ż��typeid()�ı��ʽ��ֵ������ĳ�����Ͳ������麯��
	 *	��typeid()���ڵ��Ǿ�̬���ͣ�����ʱ������ͣ�,��Ȼ�Ƕ�������ͣ��������Ͳ���Ҫ�Ա��ʽ��ֻҲ֪�����ʽ�����͡�
	 *	
	 */

	//type_info����
	int aa = 11;
	const type_info&aa_reference = typeid(aa);//����ֵ��type_info��̬����
	cout << aa_reference.name() << endl;
	
	
	system("pause");
	return 0;
}

/*
 *(1)Rtti runtime type identification	����ʱ����ʶ��
 *ͨ������ʱ����ʶ�𣬳����ܹ�ʹ�û����ָ�������������ָ�����ʵ���������͡�
 *RTTI���ǿ���һ��ϵͳ�ṩ�����ǵ�����������һ�ֹ��ܣ����ֹ�����ͨ�������������ʵ�֣�
 *	1.dynamic_cast��������ܹ��������ָ��������ð�ȫ��ת��Ϊ�������ָ��������á�
 *	2.typeid�����������ָ�����������ָ�����ʵ�����͡�
 *	ע�⣺Ҫ����������������������ڻ����б�����һ���麯������Ȼ�Ļ�����������������Ľ���ͺ�Ԥ��Ĳ�ͬ��
 *		ֻ���麯�����ڣ�������������Ż�ʹ��ָ������������󶨵Ķ�̬���͡�
 *		���򣬱����ʱ���ȷ���˵����ĸ����͡�
 *(2)typeid(����(ָ�룬����))�����
 *	Ҳ������typeid(���ʽ)
 *	�õ�������Ϣ��typeid�ͻ᷵��һ��������������ã��������������һ����׼�����ͣ�type_info(�ࡢ������)
 *	��Ҫ������
 *		1.  typeid().name()���س������������
 *		2.
 *	��Ҫ���ڣ����ڱȽ�����ָ���Ƿ�ָ��ͬ�����͵Ķ���
 *		1.����ָ�붨���������ͬ
 *	
 *(3)RTTI���麯����
 *C++������������麯�����������ͻ�Ը������һ���麯����
 *�麯�������кܶ��ÿһ���һ��ָ�룬ÿ��ָ��ָ�������������麯������ڵ�ַ��һ�����ж���麯����
 *�麯���������棬��һ����������⣬��ָ��Ĳ����麯������ڵ�ַ����ָ���ʵ������������type_info()����
 *
 *
 *
 * ÿ�����������һ��ָ������麯�����ָ�롣
 * �麯�����һ����type_info()���ͣ�����˵��ʵ�ʵ���������͡�����������߸���ĺ������麯����
 */