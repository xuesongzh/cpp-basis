#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;

class Time
{
private:
	mutable int Hour;	//mutable����
	int Minute;
	int Second;
public:
	explicit Time(int Hour, int Minute, int Second);
	Time(int Hour);
	Time(){}
public:
	void AddHour(int TemHour)const
	{
		//��mutable����һ����Ա�������ͱ�ʾ�����Ա������Զ���ڿ����޸�״̬����ʱ��const����Ա������.
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

	const Time myTime02;
	myTime02.AddHour(12);
	
	

	
	system("pause");
	return 0;

}


/*
*(1)mutable ���ȶ������׸ı��<---->const
*	mutable���������Ϊ��ͻ��const�����ơ�
*	����Ա����������const���ǲ����޸ĳ�Ա������ֵ���������const����Ա�������޸ĳ�Ա������ֵ��������mutable��
*(2)mutalbe��Ϊ��ͻ��const���ƶ�����һ�����š�
*2019��11��16��21:15:45
* Sunrise�ڶ���������ѧ�ڶ���ѧ¥1121ʵ����
*(3)
*
*/