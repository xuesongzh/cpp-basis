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
	Time() = default;	//������Ĭ�ϴ���������
public:
	//���������==
	bool operator==(Time&myTime01);

};

Time::Time(int TemHour, int TemMinute, int TemSecond) :Hour(TemHour), Minute(TemMinute), Second(TemSecond)//����ʽ������ֵ����Ա����
{
}
Time::Time(int Hour)
{
	this->Hour = Hour;
}

//���������==
bool Time::operator==(Time& myTime01)
{
	if ((this->Hour==myTime01.Hour)&&(this->Minute==myTime01.Minute)&&(this->Second==myTime01.Second))
	{
		return true;
	}
	return false;
}


int main(void)
{
	Time myTime01 = Time(12, 12, 12);
	Time myTime02(12, 12, 12);

	//������������==�����ʱ������ᱨ��  ��û�������ֲ���ƥ��ġ�==���������
	if (myTime01==myTime02)
	{
		cout << "�ж�����Time�����" << endl;
	}
	
	system("pause");
	return 0;

}


/*
*(1)Ϊʲô��Ҫ���������������
*	���ж������Ƿ���ȣ�ʹ��==�жϣ������������>= <= !=�ȿ��Խ��������͸����������㡣��ʵ�ڲ��Ѿ����е����ء�
*	ͬ��������cout<< cin>>�����������������ָ������������ݣ���ʵ�����ڲ��Ѿ�����Щ�������������ͽ��������ء�
*	���Բſ���������ֻ���������������������
*
*	��������Ҫ���Լ����������в��������ж��Ƿ����ʱ�򣬣�����Ҫ���������
*(2)ʲô����������أ�
*	˵���ˣ�����дһ����Ա�����������Ա�������־ͽ�	operator �������   operator ==,ʵ���ж��������Ƿ����
*	���������߼����ɿ�����д�ġ�
*
*	���õ�ʱ��Ϊ myTime01.operator==(myTime02) �ȼ���myTime01==myTime02
*	
*(3)��������ر�������һ�����������������������:operator ���ص������
*	��������һ����������ô���к���3Ҫ�أ��������֣���������ֵ�����������б�
*	������ǲ���������������ڼ򵥵���������縳ֵ�����ϵͳ���Զ�����һ�������ǶԸ��ӵ����������==��ϵͳ�������ɡ�
*
*	ע�⣺(1)��Ա�������Լ���һ��������������thisָ�����档
*
*/