#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;


int main(void)
{
	//��ֵ����
	int number01 = 10;
	int&reference_number01 = number01;
	reference_number01 = 20;

	//2const ����
	const int reference_number02 = number01;

	//��ֵ����-�󶨵���ֵ  ��ʱ
	int&& reference_number03 = 3;//ʹ����3֮����Ҫ����
	reference_number03 = 12;


	//��ֵ����   ָ�����ָ��һ���գ����Բ���ʼ�����������ñ����ʼ��
	//û�п����ã���ֵ���ó�ʼ����ʱ��Ͱ󶨵���ֵ
	int number04 = 200;
	int&Reference_number05 = number04;
	//int &number06 = 4;//error ��ֵ���ò��ܰ󶨵���ֵ������󶨵���ֵ
	const int &tem = 3;//const���ÿ��԰󶨵���ֵ��const���ñȽ����⡣ϵͳ�ڲ�������һ����ʱ����
	/*
	 * temValue=3;
	 * int&tem=temValue;
	 */

	//��ֵ����--�����ǰ󶨵���ֵ�����á�ʹ��&&��--����ʱ������
	int &&reference_number07 = 3;	//��ֵ���ÿ�������һ����������֡�



	//��������
	string str{ "jisuanjizuchengyaunli" };
	string &reference_str = str;
	//string &reference_str02{ "jisuanizuchengyaunli" };//error�����ԣ���ֵ���ò��ܰ󶨵���ʱ����
	//��ʱ������ϵͳ������ֵ
	//
	const string &reference_str03 = "jisuanjizuchengyuanli";//ok
	//const�������԰󶨵���ֵ�����ҿ���ִ����ʽ����ת��������ʱ����󶨵�string��ʱ�����С�
	
	//string &&reference_str04{ str };//error,��ֵ���ò��ܰ붡����ֵ
	string &&reference_str05{ "jisuanjizjiifisidf" };//���԰󶨵���ʱ����

	int number06 = 100;
	int&reference_number08 = number06;
	//int&&reference_number09 = number06;//error

	//��ֵ����󶨵���ֵ
	int &&reference_nubmer10 = number06 * 100;//ok

	//Ϊʲôǰ���������һ����ֵ���ʽ??
	/*++i;
	 *ϵͳֱ�����ڲ�������i��1��Ȼ�󷵻�i����
	 * ��Ϊi�Ǳ��������Կ��Ա���ֵ����ֵ����һ������
	 *
	 * i++Ϊʲô��һ����ֵ���ʽ������
	 * ���ú�ӣ�
	 * �Ȳ���һ����ʱ��������¼��ֵ����ʹ�ã��ٸ�i��1�����ŷ��������ʱ��������ʱ��������ֵ��
	 */

	int number11 = 300;
	(++number11) = 199;//number11=199
	//(number11++) = 2000;//error
	int&&reference13 = number11++;//�ɹ�����ֵ������reference11�󶨵Ĳ���number11,�󶨵��Ƿ��ص���ʱ��

	//std::move()����--��ֵת��Ϊ��ֵ
	int number14 = 14;
	int&&reference_number15 = std::move(number14);//ok
	reference_number15 = 15;
	cout << reference_number15 << endl;	//15,���԰�

	int &&reference_nubmer16 = 100;
	int&&reference_number17 = std::move(reference_nubmer16);	//ok ��һ����ֵ����ת��Ϊ��ֵ


	string str18 = "jisuanjizuchegnaun";//û���ƶ���������string����ƶ����캯�����ƶ����str18����ˡ�reference19�����¿��ٵ��ڴ档
	//string reference19 = std::move(str18);
	
	//��һ����ֵ�󶨵���ֵ��
	string &&str20 = std::move(str18);
	
	system("pause");
	return 0;
}

/*
*(1)���÷���
*	1.��ֵ����-�󶨵���ֵ
*	2.��������-���ı�ԭ����ֵ
*	3.��ֵ����  ʹ��&& c++11��׼
*(2)��ֵ������ʲô��
*	�������ң��󶨵���ֵ��
*
*(3)��ֵ���ã�����󶨵���ֵ��
*Ϊʲô������ֵ���ã�
*	ϣ����ֵ��������һЩ�������ٵĻ���һЩ��ʱ�����ϡ�
*�ܽ᣺�ܰ󶨵���ֵ�ϵĶ���һ�㲻�ܰ󶨵���ֵ�ϡ�
*	������ֵ���õĺ�����ͬ��ֵ���±꣬�����ã���ǰ�õ����ݼ���������Ƿ��ر��ʽ�����ӡ�
*	���ǿ��Խ�һ����ֵ���ð󶨵����б��ʽ�Ľ���ϡ�
*
*	���ط��������͵ĺ�������ͬ��������ϵ���Լ����õ����ݼ��������i--��,���ܽ�һ����ֵ���ð󶨵�����
*	���ʽ�ϣ����ǿ��Խ�һ��const������ֵ���ð󶨵����б��ʽ�ϡ�
*
*1.���еı�����������ֵ����Ϊ�������ɵ�ַ��
*2.�κκ������βζ�����ֵ����void function(int&a);a��Ȼ�����ã���������ֵ
*3.��ʱ��������ֵ��
*
*
*(4)��ֵ����Ŀ��
*	1.��ֵ������c++11���¸��������Ϊ&&��һ���µ��������ͣ����������µ���������Ŀ�ļ�2.
*	2.����&&��Ϊ���������Ч�ʣ��ѿ����������ƶ��������������Ч�ʡ�����ʱ����Ҫ�����ڴ棬
*		Ȼ����һ��һ��������ƶ�ֱ�Ӱ��ڴ��ָ��ת��B��������Ҫ�����ڴ档������ƶ����캯���½ڡ�
*	3.�ƶ���������η����ģ���ô�����ƶ�����
*		����һ���������һ������ֵ���ƶ��ƶ����캯�����ƶ���ֵ���������Ҫ�Ĳ�������ֵ���ã�
*		�������캯������ֵ�������Ҫ�Ĳ�������ֵ����
*
*(5)std::move()����
*	std::move()ֻ��һ��Ŀ�ģ���һ����ֵ��ǿ��ת��Ϊһ����ֵ��--�����һ����ֵ���԰���ȥ�ˡ�
*
*2019��11��22��16:00:10
* Sunrise�ڶ���������ѧ�ڶ���ѧ¥1121ʵ����
*
*/