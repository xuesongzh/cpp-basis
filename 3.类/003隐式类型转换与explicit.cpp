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

Time::Time(int Hour, int Minute, int Second)//����ʽ������ֵ����Ա����
{
	this->Hour = Hour;
	this->Minute = Minute;
	this->Second = Second;
}
Time::Time(int Hour)
{
	this->Hour = Hour;
}

void functionTransform(Time TemTime)
{
	return;
}

int main(void)
{
	Time myTime01 = 12;
	//Time myTime03(12, 23, 43, 54);	//����
	Time myTime04 = { 16 };
	//�������ڲ����Ե���һ������	--�����һ�������Ĺ��캯����explicit�ͻ������ʽ����ת�����������
	Time myTime02=(12, 23, 43, 54);	//����õ������Ĺ��캯��--�൱�ڶ��ű��ʽ�������Hour=54

	functionTransform(12);	//���Ȼ����һ�������Ĺ��죬����һ��Time��ʱ����

	//explicit��ֹ��ʽ����ת��
	//Time myTime05 = { 12,12,12 };	//���󣬲�����ʽ����ת��
	Time myTime06(2, 12, 34);//��ȷ�����ù��캯��
	Time myTime07=(2, 12, 34);//��ȷ�����ù��캯��
	/*
	 * �ܽ᣺һ�������Ϊ()�ǲ�����{}��һ������
	 * (1)���ڵ��������Ĺ��캯����һ������Ϊexplicit,����������ԭ��
	 */

	system("pause");
	return 0;

}
/*
 *(1)��ʽ����ת����explicit
 *		����ϵͳ˽�����˺ܶ����ǲ�֪�������飬�����������������Ͳ�ƥ��ʱ��ͻ������ʽ����ת��
 *(2)�Ƿ����ǿ��ϵͳ��ȷҪ���캯������ǿ������ת����
 *	���ԡ�������캯��������explicit(��ʽ��)����������캯��ֻ�����ڳ�ʼ����ʽ����ת�������ܽ�����ʽ����ת����
 *(3)
 * 
 */