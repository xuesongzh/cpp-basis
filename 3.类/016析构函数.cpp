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
	~Time()
	{
		cout << "��������ִ��" << endl;
	}
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
void playObj()
{
	Time myTime01 = Time(12, 12, 12);
	Time myTime02 = myTime01;	//��ʼ��--���ÿ������캯��
	Time myTime03;

	myTime03 = myTime01;	//����Ǹ�ֵ�������ϵͳĬ������

}

int main(void)
{
	playObj();

	system("pause");
	return 0;

}


/*
*(1)��������--�빹�캯���෴���������ٵ�ʱ��ͻ���ù��캯����
*������ǲ�д�Լ��������������������ͻ�Ϊ��������һ��Ĭ�ϵ�����������
*�ڹ��캯������newһ���ڴ棬��Ҫ���������������������delete�����ͷ��ڴ档
*��������Ҳ����ĳ�Ա��������~����(){}��û�з���ֵ���������κβ��������ܱ����ء�����ֻ����һ������������
*
*�������أ�����������ͬ�����Ǻ����Ĳ����������������ͣ�����˳��ͬ��
*	��ô���ǵ��õ�ʱ�����ݲ������ͣ�������˳�������ò�ͬ�ĺ�����
*
*(2)���캯���ĳ�Ա��ʼ��
*	���캯�����Ĺ������Է�Ϊ�����֣�
*		1.������֮ǰ����ʼ���б����ʽ������������ʼ����ĳ�Ա���Եġ�
*		2.�������жԳ�Ա�����Ĳ����Ǹ�ֵ�����ǳ�ʼ���������˷���ϵͳ��ʼ����һ�λ��ᣬ��ΪϵͳҲ���һ��Ĭ��ֵ��ʼ����
*	��������Ҳ��2���֣�
*		1.����������ִ�к�����{}�������ͷ��ڴ�Ȳ����������Լ�new�����Ķ�����
*		2.������֮����ϵͳ���ٶ��󣨳�Ա������������ϵͳ���٣����������ֶ����١�
*
*(3)��Ա�����Ĵ���������ʱ��
*	���������ʱ���ȶ�����ȳ�ʼ����ÿ����Ա�����ǰ��ճ�Ա���������˳������ʼ�����ȶ���ĳ�Ա��������ֵ��
*	���ٵ�ʱ���ȶ����ʱ�򣬺����١�
*
*
*/