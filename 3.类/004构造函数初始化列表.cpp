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

};

Time::Time(int TemHour, int TemMinute, int TemSecond):Hour(TemHour),Minute(TemMinute),Second(TemSecond)//����ʽ������ֵ����Ա����
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
 *(1)���캯����ʼ���б�
 *	1.ֱ���ڹ��캯����ʵ���У��ں��������б���棺��Ա��������ʼ���βα���(��ʼֵ)��,��Ա����ֵ2����ʼ���βα���2����
 *	����д��ִ��ʱ����ִ��{}ǰ��ʼִ�У��Ժ����������ʹ�ù��캯����Ա��ʼ���б���ʽ�ġ�
 *	2.����ʹ�ù��캯����ʼ���б���ʽ����ʼ���б���ʽ�г�ʼ����д��{}�еĽи�ֵ����(�ڳ�ʼ����ʱ���Ǹ�����ֵ)��д��{}
 *		�൱�ڷ����˳�ʼ������ϵͳ��һ������ֵ��
 *	3.ÿ����Ա�����ĳ�ʼ��˳���ϵͳ����˳���йأ����빹�캯����ʼ���б��д��˳���޹ء�
 *
 *(2)Ϊʲô��Ҫ���캯����ʼ���б�
 *	1.��ʼ���������ȴ���һ������ֵ��Ȼ���ٸ�ֵ��
 *	2.��Щ����ֻ��ʹ�ó�ʼ���б�ķ�ʽ��

*/