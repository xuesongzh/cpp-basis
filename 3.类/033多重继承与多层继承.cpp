#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

class GrandFather1
{
public:
	int myValueGrand;
public:
	GrandFather1(int i):myValueGrand(i)
	{}
	virtual ~GrandFather1()
	{
		cout << "GrandFather1����������ִ��" << endl;
	}
	void myInfo()
	{
		cout << "����GrandFather01" << myValueGrand << endl;
	}
	
};

class GrandFather02
{
public:
	int myValueGrand02;
public:
	GrandFather02(int i) :myValueGrand02(i)
	{}
	virtual ~GrandFather02()
	{
		cout << "GrandFather1����������ִ��" << endl;
	}
	void myInfo()
	{
		cout << "����GrandFather02" << endl;
	}

};

//���常��
class Father:public GrandFather1
{
public:
	int myValueFather;
public:
	Father(int i,int k):GrandFather1(i),myValueFather(k)
	{
		;
	}
	//Father����������
	virtual ~Father()
	{
		cout << "����Father�����������" << endl;
	}
	void myInfo()
	{
		cout << "����Father" << endl;
	}
};



class Son:public Father
{
public:
	int myValueSon;
public:
	Son(int i,int j,int k):Father(i,j),myValueSon(k)
	{
		
	}
	virtual ~Son()
	{
		cout << "����son���ϴͷ����"<<endl;
	}
	void myInfo()
	{
		cout << "����son"  << endl;
	}
};
//��Father02ͬʱ�̳�����GrandFather��

class Father02:public GrandFather1,public GrandFather02
{
public:
	int myVlaueFather02;
public:
	Father02(int i,int j,int k):GrandFather1(i),GrandFather02(j),myVlaueFather02(k)
	{}
	virtual ~Father02()
	{
		cout << "������Father02�����������" << endl;
	}
	void myInfo()
	{
		cout << "����Father02,�̳�������Grandfather1��02" << endl;
	}
	
};

class Son02:public Father02
{
public:
	int myValueSon02;
public:
	Son02(int i,int j,int k,int m):Father02(i,j,k),myValueSon02(m)
	{
		;
	}
};

int main(void)
{
	Father02 my_father01(1, 2, 3);//�ȵ�������GrandFather�Ĺ��캯��
	my_father01.myInfo();//����Father02��ĺ���
	my_father01.GrandFather02::myInfo();//���ø����myInfo����
	
	
	system("pause");
	return 0;
}

/*
*(1)���ؼ̳�
*����Ӷ������̳в�������ж��ؼ̳С�
*c�̳���B��B�̳���A����ô�ж��̳С�C-->B-->A
*
*
*(2)�̳й�ϵson-->father-->grandfather
*
*son2--Father02-->GranFather1,GrandFather02
*
*
*
*
*/