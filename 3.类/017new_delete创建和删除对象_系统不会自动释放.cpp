#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;

class Time
{
private:
	int Hour;
	int Minute;
	int Second;
public:
	explicit Time(int Hour, int Minute, int Second);
	Time(Time&TemTime);
	Time(int Hour);
	Time();
	~Time();
	

};

Time::~Time()
{
	cout << "��������" << endl;
}


Time::Time(int TemHour, int TemMinute, int TemSecond) :Hour(TemHour), Minute(TemMinute), Second(TemSecond)//����ʽ������ֵ����Ա����
{
}
Time::Time(int Hour)
{
	this->Hour = Hour;
}
//�������캯��
Time::Time(Time& TemTime)
{
	this->Hour = TemTime.Hour;
	this->Minute = TemTime.Minute;
	this->Second = TemTime.Second;
}
Time::Time()
{
	;
}


int main(void)
{
	Time myTime01(12, 12, 12);
	Time myTime02 = myTime01;	//��ʼ��--���ÿ������캯��
	Time myTime03;

	myTime03 = myTime01;	//����Ǹ�ֵ�������ϵͳĬ������


	//ʹ��new��������,���ص��Ǵ��������ָ�루��ַ��
	Time *Ti = new Time;//���ò��������Ĺ��캯��
	Time*Ti2 = new Time();//���ò��������Ĺ��캯�� ----���������о�


	//new�����Ķ�������Լ��ֶ��ͷ�
	delete Ti;	//������������
	delete Ti2;
	system("pause");
	return 0;

}

/*
 *(1)new�����ʱ�����ϵͳ�Ĺ��캯����
 *	��������new�����Ķ��󣬱����Լ��ͷţ�ϵͳ����������ͷš�
 *	��ϵͳֹͣ���е�ĳ��ʱ��֮ǰ�����Լ�ʹ��delete�ͷš�
 *	��ʲôʱ��deleteϵͳ�ͻ��������������
 * (2)
 * (3)
 */
