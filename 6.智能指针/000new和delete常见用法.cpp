#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;



int main(void)
{
	static  int j = 23;//�ֲ���̬�����ھ�̬�������ڴ�

	int i = 10;//��ϵͳ���з�����ͷ�
	int *p1 = new int;//��̬�ڴ���䣬��ֵδ����
	string *s1 = new string;//���ַ�����ϵͳ����stringĬ�ϵĹ��캯��
	string *s2 = new string(5, 'a');//aaaaa


	vector<int>* pointVector = new vector<int>{ 1,2,3,4,5 };//ע�����������Ǵ��int��vector*����
	

	//ֵ��ʼ��
	string *s3 = new string();//�ÿ���������ʼ���ͽ�ֵ��ʼ��
	int *p2 = new int();//ֵΪ0������δ��
	//new���������ʱ���ܹ����С�ֵ��ʼ�����ͽ��г�ʼ������ֹû�г�ʼ����������
	//
	//c++11�У�auto���Ժ�new���ʹ��
	string *s4 = new string("jisuanjizu");
	auto s5 = new auto(s4);//s4,s5ָ��ͬһ���ڴ� s5��string**���� ָ���ָ��


	//const����Ҳ���Զ�̬����
	const int*p4 = new const int(200);


	
	system("pause");
	return 0;
}

/*
*(1)ֱ���ڴ���� new delete
*	��һ�������ڶ���һ�����󣬵���һ���뿪�����������������ʧЧ�ˣ����Ǿֲ�����
*	��̬�ֲ�����
*	1.new�����ڴ淽ʽ���ǳ�Ϊ��̬���䣬�����ڶ��ϣ�ֱ���ɳ���Ա�����ڴ����
*	delete�����ǻ���new������ڴ�--�ͷ��ڴ档����new������ڴ棬����ʹ��deleteʹ�á�
*	2.delete�ͷ�һ���ڴ棬ֻ��deleteһ�飬����delete��Ρ�
*	3.��ָ����Զ��ɾ��������ûʲô���塣
*	4.new�������ڴ�һ����Ҫ����delete,�����ڴ�й©��ʱ��һ��������Դ���ţ����б�����
*	5.delet����ڴ治Ҫ��ʹ�á�
*	6.ָ�벻ָ���κ��ڴ�ռ䣬Ҫָ��null.
*	7.ͬһ���ڴ��ͷ����Σ�Ҳ�ᱨ�쳣��
*	8ʹ��new��delete�����ڴ����Ҫʮ��С�ġ�
*		c++11�������ˡ�����ָ�롱����������delete������ָ����Զ�����delete
*
*(2)�����¹��̣��۲��ڴ�й©
*MFCӦ�ó�����һ�������ϣ������˳���ʱ�򣩣��ܰ������Ƿ����ڴ�й©��
*
*(3)
*
*
*/