#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;

class Student
{
public:
	int number;
	int age;
};


class Time	//����һ��ʱ����
{
public:
	int Hour;
	int Minute;
	int Second;
private:
	//int MilliSecond;//˽�еĳ�Ա���ԣ����������ⲿ����
	//��Ա����
public:
	Time()	//Ĭ�Ϲ��캯��
	{
		;
	}
	Time(int TemHour,int TemMinute,int TemSecond)
	{
		Hour = TemHour;
		Minute = TemMinute;
		Second = TemSecond;
	}

	//һ����ͨ�ĳ�Ա���Գ�ʼ������
	void InitTime( int TemHour, int TemMinute, int TemSecond)
	{
		Hour = TemHour;
		Minute = TemMinute;
		Second = TemSecond;
	}
	
};

//��ʼ��ʱ����ĺ���--c���Է���д��
void InitTime(Time&TemTime/*�������*/,int TemHour,int TemMinute,int TemSecond)
{
	TemTime.Hour = TemHour;
	TemTime.Minute = TemMinute;
	TemTime.Second = TemSecond;
}

int main(void)
{
	//.��Ա��ʽ����
	Student stu1={100,12};
	cout << stu1.number << endl;
	//ָ�뷽ʽ����
	Student*pstu1 = new Student;
	pstu1->number = 200;
	pstu1->age = 13;
	

	//(2)�����
	Time myTime;	//����Ĭ�Ϲ��캯��
	InitTime(myTime, 12, 12, 30);	//12:12:30
	
	Time myTime2(18,35,30);	//������ô������Ĺ��캯��
	//c���Եĳ�ʼ������ ��Ա���Ժͳ�Ա����û�о���Ĺ�ϵ
	myTime.InitTime(13, 13, 45);

	//��3�����󿽱�--�������ǵ��ÿ������캯��--��ĳ�Ա����
	//Ĭ������£����ֶ���Ŀ�������ÿ����Ա�����������
	//�ں��������Time�ж����ʵ��ġ���ֵ�����������ʵ�����ֿ�����Ϊ��--->���������
	Time myTime03(myTime);
	Time myTime04=myTime;
	Time myTime05 = { myTime };
	Time myTime06 { myTime};
	myTime06.Hour = 8;
	//4�ַ�ʽ�����Գ�ʼ����

	system("pause");
	return 0;
}

/*
* (1)�����
*	1��һ��������û��Լ�������������ͣ����ǿ��԰��������һ�������ռ䣬����һ�Ѷ�������Ա��������Ա������
*	2��һ�������ɣ���Ա���������ԣ���Ա����--�ɺܶ�����ĳ�Ա���������죬�������ͳ�Ա���ԣ�thisָ�룩
*	3���������Ա��ʱ�����������󣬾����� ������.��Ա��  ������
*		���ʹ��ָ������ָ�������ʣ���ʹ�� ����ָ��->��Ա����
*	4��public��Ա�ṩ��Ľӿڣ����ⲿʹ�ã�private��Ա�ṩ����ʵ���๦�ܵ�ϸ�ڷ�����
*		���ǲ���¶��ʹ���ߣ�����޷�ʹ����Щ��Ա������ֻ�������ڲ�ʹ��
*	5.struct�ĳ�Ա����������Ĭ����public��class����ĽṹĬ����private�ġ�
*	6.
*(2)��Ա����
*
*��3������Ŀ���
*��4��˽�г�Ա
*/