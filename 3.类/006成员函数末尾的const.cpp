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
	Time()
	{}
public:
	void AddHour(int TemHour)const;
	void test(string& str)
	{
		cout << str << endl;
	}
};

Time::Time(int TemHour, int TemMinute, int TemSecond) :Hour(TemHour), Minute(TemMinute), Second(TemSecond)//����ʽ������ֵ����Ա����
{
}
Time::Time(int Hour)
{
	this->Hour = Hour;
}

//������Ա����--�����޸ĳ�Ա������ֵ
void Time::AddHour(int TemHour) const
{
	//Hour = Hour + TemHour;	//error�����޸ĳ�Ա����������
	
}


int main(void)
{
	Time myTime01 = Time(12, 12, 12);
	const Time myTime02;	//����const�������ֶ���һ����ʼ���Ͳ����޸ġ�
	myTime02.AddHour(12);
	//myTime02.test();	//�����ݵ����η��ţ����ܵ��÷�const������
	
	/*1.s����Ϊconst�Ķ����ܵ�����ͨ�ĳ�Ա����
	 *2.�������ֶ�����Ե���const������Ա����
	 *3.const���ܷ�����ͨ������ĩβ
	 * 
	 */
	system("pause");
	return 0;

}


/*
*(1)�ڳ�Ա����(�����Ͷ���)��������const
*	���ã�����ϵͳ�������Ա�����������޸ĸö��������κγ�Ա������ֵ��
*		Ҳ����˵�������Ա���������޸���Time���κ�״̬��
*		�����һ��const�ĳ�Ա����Ҳ�г�����Ա����
*(2)
*(3)
*
*/