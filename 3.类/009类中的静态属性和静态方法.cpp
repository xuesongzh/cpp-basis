#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;
static int number02 = 10;	//ȫ�־�̬�������������Ƕ�����ļ���
//�����ڱ��ļ��У������������ļ���ʹ��extern���������á�
//
//�ֲ���̬����������һ�ε��õ�ʱ������ֵ���ٴν���ʱ�򲻻�ִ�г�ʼ������
void myFunction()
{
	static int number1 = 5;//�ֲ���̬����������������ֵ�����ھ�̬�洢����
	//�ڶ��ε��õ�ʱ��ִ�����������ֵֻ����ʼ��һ�Σ������ٴ�ִ�г�ʼ�������ǿ����޸�
	number1 = 10;
}


class Time
{
public:
	int Hour;
	int Minute;
	int Second;
public:
	explicit Time(int Hour, int Minute, int Second);
	Time(int Hour);
public:
	//��̬��Ա���Ժ;�̬��Ա����
	static int myCount;	//��̬��Ա������������û�з����ڴ棬���������ﲻ�ܳ�ʼ��,����������ʽ��ʼ��
	static void myStaticFunction(int testValue);
};



Time::Time(int TemHour, int TemMinute, int TemSecond) :Hour(TemHour), Minute(TemMinute), Second(TemSecond)//����ʽ������ֵ����Ա����
{
}
Time::Time(int Hour)
{
	this->Hour = Hour;
}
//��̬��Ա����
void Time::myStaticFunction(int testValue)
{
	myCount = testValue;
	//Hour = 12;	//error���Ǿ�̬��Ա���ԣ������ھ�̬��Ա��������
}

//��̬��Ա������ʽ��ʼ��-�����ڴ�
int Time::myCount = 0;
int main(void)
{
	
	Time myTime01 = Time(12, 12, 12);
	Time myTime02(02, 34, 54);

	Time::myCount = 100;
	cout << myTime01.myCount << endl;

	//��ζ��徲̬��Ա������һ����һ��.cpp�ļ��Ŀ�ͷ���徲̬��Ա�����������������κκ���ǰ����з����ڴ档

	//��̬��Ա����
	//ʹ�������
	Time::myStaticFunction(14);
	//ʹ����������
	myTime01.myStaticFunction(45);
	
	system("pause");
	return 0;

}


/*
*(1)static��Ա��ȫ�־�̬������ֲ���̬����
*
*(2)��û��һ����Ա������������������ĳ���࣬������ĳ�����󣿣�
*	����������ĳ�Ա�����о�̬��Ա������static��Ա����
*	�ص㣺������ĳ�����󣬶������������࣬һ����ĳ���������޸���static��Ա������ֵ��
*		�����������ֱ�ӷ��ʡ�
*		2�����ֳ�Ա����ֻ��һ��������ʹ��ʱ  ����������Ա������
*		3.��Ա����ǰ��Ҳ���Լ�static�����ɾ�̬��Ա������������ĳ�Ա������ʱ��
*			����::��Ա��������
*			��̬��Ա����ֻ�ܲ�����̬��Ա����.
*(3)
*
*/