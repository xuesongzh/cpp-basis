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
public:
	void AddHour(int TemHour)
	{
		Hour = Hour + TemHour;
	}

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
	Time myTime01 = Time(12, 12, 12);

	system("pause");
	return 0;

}

/*
*(1)���ඨ����ʵ�ֳ�Ա����inline�����ڵĳ�Ա����ʵ����ʵҲ����ĳ�Ա�������塣
*	AddInline()��������Ķ�����ʵ�ֵĳ�Ա�������ᱻ����inline��������������
*	�ܲ��������ɹ���ȡ���ھ���ı�������
*
*(2)
*(3)
*
*/