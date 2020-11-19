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
	Time() = default;

public:
	//���ظ�ֵ�����
	Time& operator=(const Time&TemTime);

};

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

//���ظ�ֵ�����
Time& Time::operator=(const Time& TemTime)	//����д��const����������
{
	this->Hour = TemTime.Hour;
	this->Minute = TemTime.Minute;
	this->Second = TemTime.Second;
	return *this;
}



int main(void)
{
	Time myTime01 = Time(12, 12, 12);
	Time myTime02 = myTime01;	//��ʼ��--���ÿ������캯��
	Time myTime03;
	
	myTime03 = myTime01;	//����Ǹ�ֵ�������ϵͳĬ�����أ�û�е��ÿ������캯��
	//ϵͳ�����һ��������ֵ�����,���ǿ����Լ����������������,���غ�������غ�����غ���
	//myTime03���Ǹ�ֵ��������ط��ص�*this
	//�ȼ���
	myTime03.operator=(myTime01);
	
	system("pause");
	return 0;

}


/*
*(1)������ֵ�����
*	���ǿ����Լ����ظ�ֵ����������û�����أ��������Զ����ɵĸ�ֵ��������رȽϴֲڣ�һ����ǽ���static
*	��Ա���Ը�ֵ����������Ķ���ĳ�Ա��ȥ�������Ա������󣬿��ܻ�Ҫ������Ŀ������캯����
*(2)���ظ�ֵ�����
*	�з������ͺͲ����б�����Ĳ����ͱ�ʾ����������������void operator=(Time&TemTime);�е�TemTime
*	�������־���operator=
*
*	��ֵ���������һ�㷵��������������á�
*(3)
*
*2019��11��18��15:28:51
* Sunrise�ڶ���������ѧ�ڶ���ѧ¥1121ʵ����
*/