#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include <memory>
#include <set>
#include <map>
#include <list>
#include <array>

using namespace std;

class A
{
public:
	A()
	{
	;
	}

public:
	int m_i;

};

int main(void)
{
	char*p1 = new char[10];
	

	memset(p1, 0, 10);
	delete[]p1;
	/*��ʾ�ͷ�1���ֽڣ�
	 *
	 * һ���ڴ�Ļ���Ӱ�췶Χ�������Ƿ����С���ڴ棬ǰ���ڴ涼����Ӱ�졣
	 * �����ڴ��ʱ���н��н����ڴ�����ռ�õ��ڴ棬���¼�ڴ�Ĵ�С��ռ�õ��ڴ棬Ҳ��Ҫ�ͷš�
	 */


	int*p2 = new int(100);
	delete p2;
	/*���ٵ��ԣ������ڷ����ڴ汣�����ݣ�0x64��ǰ����04��¼�����ڴ�Ĵ�С��
	 *  0x0038CFC4  00 00 00 00 01 00 00 00 04 00 00 00 44 00 00 00 fd fd fd fd  ............D...????
		0x0038CFD8  64 00 00 00 fd fd fd fd 52 78 b2 55 08 94 00 03 90 00 36 00  d...????Rx?U.?..?.6.

		�����ڴ治�Ǽ򵥵ķ���4���ֽڣ�����4���ֽ���Χ�����������˺ܶദ�������¼������ֽ����ȡ�
	��ϸ��malloc�����ڴ�ʾ��ͼ
		�����ڴ�ʱ��Ϊ�˼�¼�͹����ڴ棬���������˲����ڴ棬����˷ѣ�������Ƶ������С���ڴ棬��ɵ��˷Ѹ������ԡ�
	 */

	
	system("pause");
	return 0;
}

/*
*(1)new�ڴ����ϸ��̽��
*2019��11��29��17:12:35
* Sunrise�ڶ���������ѧ�ڶ���ѧ¥1121ʵ����


*(3)
*
*
*/