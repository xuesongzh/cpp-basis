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
	Time(int Hour);
    Time(){}

};

Time::Time(int TemHour, int TemMinute, int TemSecond) :Hour(TemHour), Minute(TemMinute), Second(TemSecond)//����ʽ������ֵ����Ա����
{
}
Time::Time(int Hour)
{
	this->Hour = Hour;
}


int main(void)
{
	//Time myTime01 = Time(12, 12, 12);

	Time myTime02;	//����Ĭ�Ϲ��캯��
	system("pause");
	return 0;

}


/*
*(1)Ĭ�Ϲ��캯��--û���κβ����Ĺ��캯��
*	1.���û���κι��캯����ϵͳĬ�ϸ�һ��Ĭ�Ϲ��캯�����������Զ�����һ��Ĭ�Ϲ��캯��������С��ϳɵ�Ĭ�Ϲ��캯����
*	2.һ������д�˹��캯����ϵͳ�Ͳ����Զ�����Ĭ�Ϲ��캯����
*(2)������������ʱ�򣬻����������Ķ��󣬱���ʹ�ó�Ա��ʼ���б�ͳ�ʼֵ���ֹ�д�Լ��Ĺ��캯����
*(3)
*2019��11��17��09:11:05 Sunrise�ڶ���������ѧ�ڶ���ѧ¥1121ʵ����
*
*/