#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;

//һ����ʱ��С��-����������ΪTime���һ����Ա����
class TemClass
{
public:
	TemClass()
	{
		cout << "TemClass�Ĺ��캯��" << endl;
	}

	TemClass(TemClass&tem_class)
	{
		cout << "TemClass�Ŀ������캯��" << endl;

	}
};



class Time
{
private:
	int Hour;
	int Minute;
	int Second;
public:
	//TemClass tem_class;
	
public:
	explicit Time(int Hour, int Minute, int Second);
	Time() = default;
	
public:
	//�������캯��
	Time(Time&myTime, int TemHour = 10,int Tem��inute=10,int TemSecond=10);

};

Time::Time(int TemHour, int TemMinute, int TemSecond) :Hour(TemHour), Minute(TemMinute), Second(TemSecond)//����ʽ������ֵ����Ա����
{
}



//�������캯��
Time::Time(Time& mytime/*�������Ҫ�����Ķ���*/, int temhour, int tem��inute, int temsecond):Hour(12),Minute(12),Second(12)
{
	cout << "����time��Ŀ������캯��" << endl;
	//this->hour = mytime.hour;	//ok
}


void myFunciton01(Time Te)
{
	;
}

Time myFunction02()
{
	Time t;
	return t;
}
int main(void)
{
	Time myTime01 = Time(12, 12, 12);

	//Time myTime02;	//����Ĭ�Ϲ��캯��
	//myTime02 = myTime01;	//���ﲻ�ǵ��ÿ������캯��
	//���涼��ִ�п������캯��
	
	//Time myTime03(myTime01);
	//Time myTime04{ myTime01 };
	//Time myTime05={ myTime01 };
	Time myTime06 = myTime01;	

	myFunciton01(myTime06);

	Time t = myFunction02();
	
	system("pause");
	return 0;

}


/*
*(1)Ĭ������£������Ŀ�����ÿ����Ա�������������
*(2)�������캯��
*	1.���һ����Ĺ��캯�������������������ã�����������������������Щ�����������Ĭ��ֵ��
*	����Ĭ�ϲ�����������ں��������У����Ǹú���û�к���������
*
*	2.�������캯������һ����ʱ����ϵͳ�Զ����ã�ʱ�������ж����Ƶ�ʱ�� =
*	3.���鿽�����캯����һ��������const,��һ�㲻Ҫ����explicit����ֹ��ʽ����ת����
*	4.��Ա�������������Ϊ���Ƕ���Ŀ������캯�����ڶ�ʧȥ���á�
*		���Ƕ���Ŀ������캯��ȡ����ϵͳĬ�ϵĿ������캯��
*(3)
*	1.�������û�ж���һ���������캯����������������Ƕ���һ���������캯��
*	2.�����������Ƕ���ĽС��ϳɿ������캯����--���ý�����TemTime�ĳ�Ա������������ڴ����Ķ����С�
*
*	3.Ĭ�Ͽ������죺ÿ����Ա�����;���������ο���������˵��Ա������int���ͣ���ô����ֱ�ӵ�ֵ������
*		�����Ա����������󣬾ͻ������Ŀ������캯����
*	4.����Լ������˿������캯�������ܻ�ȡ��ϵͳ�Ŀ������캯������ô����Ҫ�ڿ������캯���и�ֵ��
*		�Է�ֹ����δ��ʼ���ĳ�Ա������
*(4)����һЩ�������ÿ������캯���ĵ���
*	1.�������ݲ���
*	��һ��ʵ�δ��ݸ�һ�������������βΣ����ȵ��ù��캯�����������Ȼ����ÿ������캯����
*	2.��������ֵ��һ���ֲ���������󣬻������ʱ����Ŀ��������ÿ������캯������һ����ʱ���󷵻ء�
*/