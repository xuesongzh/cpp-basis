#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;

//һ����ģ�������
template<typename T>
void mySwap(T& a,T& b)
{
	T tem;
	tem = a;
	a = b;
	b = tem;
	
	return;
}

struct Student
{
	int number;
	string name;
};

int main(void)
{
	vector<int> v1;	//����һ��vector�������ֽ�v1���洢int���͵�����
	//<>����ģ���е����ݣ�vector�������һ����ģ�壬<int>����һ����ģ���ʵ��������,��Ҫ����������Ϣ��

	//�������һ������ģ�壬����ʵ��������
	int a = 3;
	int b = 5;
	mySwap<int>(a, b);
	cout << "a=" << a <<"\t"<< "b=" << b << endl;

	//���Դ���Զ������������
	vector<Student> stuList;	//��Žṹ��Student���͵�����
	vector<vector<string>> str_str;	//vector�е�ÿһ��Ԫ�ض���һ�����string���͵�vector
	vector<int*>v2;	//	���int*����
	//vector<int&>v3;	//������һ������������һ���������Բ��ܴ����vector������



	//1.��vector
	vector<string>myStr;	//����һ���յĴ洢string���͵�vector���󣬲������κ�Ԫ��
	myStr.push_back("abcd");
	myStr.push_back("123");

	//2.����Ԫ�ؿ����ĳ�ʼ����ʽ
	vector<string>myStr2(myStr);	//��myStrԪ�ؿ�����myStr2
	vector<string>myStr3 = myStr;	//ÿһ�����������Լ����ڴ�ռ䣬�ǿ������Ƴ�����

	//3.c++11�е��б��ʼ����ʽ{}
	vector<string>myStr4 = { "aaaa","bbbb","ccccc" };

	//4.����ָ��������Ԫ�أ���Ԫ����������Ķ�����һ��ʹ��()
	vector<int>Number1(15, 0);	//	����15��Ԫ�أ�ÿ��Ԫ�ص�ֵ��0
	vector<string>Mystr05(12, "AAAAA");
	//���������ֵ����ôϵͳ�����ó�ֵ
	vector<int>Nubmer2(20);	//0
	vector<string>myStr06(12);	//=""

	//5.������ʼ����ʽ()��ʾԪ������   {}Ԫ������  --���ǲ��Ǿ��Ե�
	vector<int>Nubmer03(10);	//��������10��Ԫ�أ�ÿ��Ԫ�ص�ֵ��ϵͳ������
	vector<int>Number04{ 10 };	//��������һ��Ԫ��10.
	vector<string>myStr07{ "hello" };		//һ��Ԫ�أ���hello�ַ���
	vector<string>myStr08{ 10 };	//�����10��int���ͣ����ַ������Ͳ�ƥ�䣬ϵͳ�Զ�����Ϊ10��Ԫ�أ�ÿ��Ԫ��Ϊ��''
	vector<string>myStr09{ 10,"AAAA" };	//10��Ԫ�أ�ÿ��Ԫ�ض���AAAA

	vector<int>Number05(10, 1);	//	10��Ԫ�أ�ÿ��Ԫ��ֵΪ1
	vector<int>Number06{ 10, 1 };	//	2��Ԫ�أ�10,1��ͬ�ڳ�ʼ���б�
	//�ܽ᣺Ҫ��ͨ��{}��ʼ���б�ķ�ʽ���г�ʼ������ô<>��������ͱ���ͺ����ƥ��
	system("pause");
	return 0;
}

/*
* (1)vector���ͼ�飺�Ǳ�׼���е�һ�����ͣ����ϻ��߶�̬���飬���ǿ��԰����ɸ���ͬ���͵Ķ���������С�
*vector�ܰ���������װ����������Ҳ����Ϊ������
*
*(2)����ͳ�ʼ��vector����
*	
*/