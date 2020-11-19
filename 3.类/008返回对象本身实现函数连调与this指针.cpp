#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;

class Time
{
private:
	mutable int Hour;
	int Minute;
	int Second;
public:
	explicit Time(int Hour, int Minute, int Second);
	Time(int Hour);
	Time(){}
public:
	//���ض��������Ӧ�ã����ض�������
	Time&AddHour(int TemHour);
	//Time&AddHour(Time *const this,int TemHour);	//�ȼ������֣�����thisָ��
	Time&AddMinute(int TemMinute);
};

Time::Time(int TemHour, int TemMinute, int TemSecond) :Hour(TemHour), Minute(TemMinute), Second(TemSecond)//����ʽ������ֵ����Ա����
{
}
Time::Time(int Hour)
{
	this->Hour = Hour;
}
//���ض������������
Time& Time::AddHour(int TemHour)
{
	//Hour = (Hour + TemHour) % 24;	//ʱ����0-24Сʱ
	this->Hour = (this->Hour + TemHour) % 24;
	cout << this->Hour << endl;	//10
	return *this;	//���ض�������
}

Time& Time::AddMinute(int TemMinute)
{
	this->Minute = (this->Minute + TemMinute) % 60;
	cout << this->Minute << endl;
	return *this;
}



int main(void)
{
	Time myTime01 = Time(12, 12, 12);
	myTime01.AddHour(22);
	//���ض������Ϳ���ʵ�ֶ�ֵ�����ĵ��ã�������cout<<����ʵ�ֵ��ö�Σ����صľ���ofstream������
	//���ض��������ʵ�ֺ����������ã���ֵ����
	myTime01.AddHour(13).AddMinute(54);
	
	system("pause");
	return 0;

}


/*
*(1)����������������  *this
*(2)thisָ��
*	ÿһ����Ա������һ�������ĳ�Ա����thisָ�룬ָ���Լ�����ĵ�ַ�������к������õ�ʱ�򣬰�thisָ��
*	���Լ�����ĵ�ַ��������һ���������ݹ�ȥ�������������Լ�д�Ĳ�����
*	��ϵͳ�������κζԳ�Ա���Եķ��ʶ���ͨ��thisָ�������ʵġ�
*(3)
*	1.���ص�thisָ��ֻ���ڳ�Ա�����У�ȫ�ֺ����;�̬������static���в�����thisָ��
*	2.����ͨ��Ա�����У�this��һ��ָ���const�����constָ�롣thisֻ��ָ��ǰ����ָ���ܸı䡣
*	3.��const��Ա�����У�thisָ�����һ��ָ��const�����constָ�롣const Time *const this
*
*�ܽ᣺
*	���ض��������ʵ�ֺ����������ã���ֵ����
*2019��11��16��21:18:54
* Sunrise�ڶ���������ѧ�ڶ���ѧ¥1121ʵ����
*/