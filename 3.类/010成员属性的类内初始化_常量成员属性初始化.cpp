#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;

class Time
{
public:
	int Hour;
	int Minute={0};
	int Second=0;	//���ڳ�ʼֵ
	//��������ʹ�ù��캯����ʼ���б�ʽ��ʼ��
	const int TestConst;
public:
	explicit Time(int Hour, int Minute, int Second);
	Time(int Hour);
	Time():TestConst(12) {}

};
//��Ԫ�����������е�˽�����ݳ�Ա���������ݳ�Ա����ֱ�ӷ��ʡ�
void ReadTime(Time&MyTime)
{
	cout << MyTime.Hour << endl;
}

Time::Time(int TemHour, int TemMinute, int TemSecond) :Hour(TemHour), Minute(TemMinute), Second(TemSecond),TestConst(12)//����ʽ������ֵ����Ա����
{
}
Time::Time(int Hour):TestConst(12)
{
	this->Hour = Hour;
}


int main(void)
{
	Time myTime01 = Time(12, 12, 12);

	//����صķǳ�Ա��������
	ReadTime(myTime01);

	//���ڳ�ʼ��
	Time myTime02;	//Minute=Second=0  
	
	system("pause");
	return 0;

}


/*
*(1)����طǳ�Ա����
*	���༸���޹صĳ�Ա����������˽�����ݳ�Ա---��Ԫ����
*	���ʹ������ݳ�Ա������ֱ�ӷ���
*(2)���ڳ�ʼ��
*	��c++11�����ǿ���Ϊ���ڳ�Ա�����ṩһ����ʼֵ�����������ʱ��ʹ�ó�ʼֵ����ʼ���ó�Ա������
*	
*(3)�������Եĳ�Ա���Ա����ڹ��캯����ʼ���б��г�ʼ������{}���ܸ�ֵ��
*
*/