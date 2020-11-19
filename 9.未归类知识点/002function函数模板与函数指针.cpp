#include<iostream>
#include<cstdlib>
#include <map>
#include <string>
#include <functional>

using namespace std;
typedef int (*myfunction)(int);//����һ������ָ�����ͣ�����ָ�����ָ�򷵻�ֵ��int���ͣ���ֻ��һ��int���Ͳ����ĺ���

//��ʵ�ֵĹ��ܣ�����һ�����ڵ���0�����֣����С��0������0
class BiggerThanZero
{
public:
	//��һ�������Ĺ��캯��
	BiggerThanZero(int a) :m_i(a)
	{
		m_i = a;
	}

public:
	//����()�������������
	int operator()(int value)const
	{
		if (value <= 0)
		{
			return 0;
		}
		else
		{
			return value;
		}
	}


private:
	int m_i;
};

//��ͨ����,��ӡvalueֵ����ԭ������.--���ò����ͷ���ֵ������������()��ͬ
int echoValue(int value)
{
	cout << value << endl;
	return value;
}

int main(void)
{
	//ͨ������ָ����ú���
	myfunction myfucntionP1 = echoValue;//������Բ���&
	int number01 = myfucntionP1(-23);
	int number02 = (*myfucntionP1)(234);//����Ҳ���Բ���*

	//ͨ��map����ɵ��ö����ָ��
	map<string, int(*)(int)>myMap;//���mapֻ��װ����ָ������
	myMap.insert({ "aa", echoValue });//����һ������ָ��

	BiggerThanZero b1(123);//���к�������������Ķ���
	//myMap.insert({ "bb",b1.operator() });//error,�﷨����
	//ͨ��function������һ���ɵ��ö���
	//function<int(int)>//������һ��function()���ͣ���������һ���ɵ��ö��󣬴�����Ƿ���ֵ��int���ͣ�����һ��int���Ͳ���
	function<int(int)>f1 = echoValue;//����ָ�룬����echoValue�к������أ��ͻ��Ҳ�����ַ������
	function<int(int)>f2 = b1;//�������Ҳok�����������������
	function<int(int)>f3 = BiggerThanZero(12);//����һ��������������ʼ��һ������ģ�����
	f1(43);
	f2(-23);
	f3(-23);


	map<string, function<int(int)>>myMap02 = { {"aa",echoValue},{"bb",b1},{"cc",BiggerThanZero(23)}};
	myMap02["aa"](12);//������["��"]==ֵ
	myMap02["bb"](234);
	myMap02["cc"](-213);
	
	system("pause");
	return 0;
}
/*
*(1)��ͬ���ö������ͬ������ʽ--functionģ��
*int echoValue(int value)�����е�int operator()(int value)const�������ͷ���ֵ��ͬ���ͽ�����������ʽ��ͬ��
*һ�ֵ�����ʽ��Ӧһ���������ͣ���������--����ֵ�Ͳ�����
*
*(2)�ɵ��ö���
*	eachValue()�����пɵ��ö���
*	�����˺�����������������
*	���ǿ��԰���Щ�ɵ��ö����ָ�뱣��������Ŀ���Ƿ���������ʱ������Щ�ɵ��ö�������������c�����еĺ���ָ��
*	ͨ��map��ֵ�������棬���ַ����������ú���ָ����ֵ��
*
*(3)��׼��functional���ͽ���
*	function ��ģ�壬Ҫ�ṩģ���������ʾ��function�����ܱ�ʾ�ĵ�����ʽ
*
*ע�⣺
*	������������أ����޷�ͨ��function�����ã�����취��ʹ�ú���ָ���������
*	2019��12��8��22��03��
*
*
*/