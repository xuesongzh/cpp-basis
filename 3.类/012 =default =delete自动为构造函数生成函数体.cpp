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
	Time() = default;	//������Ϊ=default���ֺ����Զ����ɺ�����
	//Time() = delete;	//�ñ�������ֹ����ĳ������
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

	//Ĭ�Ϲ��캯��
	Time myTime02;	//Ĭ�Ϲ��캯��
	system("pause");
	return 0;

}


/*
*(1)=default =delete
	Time() = default; �������ܹ��Զ�Ϊ�������ɺ����壬��������ĺ���
	ֻ�����ڹ��캯�����������캯�������⺯��
*(2)Time() = delete;	//�ñ�������ֹ����ĳ������
*(3)
*
*/