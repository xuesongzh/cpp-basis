#include<iostream>
#include<iostream>
#include<cstdlib>
#include<functional>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

//ȫ�ֱ�����ÿ��Ԫ�ض���function��ÿ��Ԫ�ض��ǲ�����int������ֵ��bool����
std::vector<std::function<bool(int)>> gv;

void myFunction()
{
	srand((unsigned)time(nullptr));
	int temValue = rand() % 6;//����һ��0-5֮�������
	gv.push_back(
		[&](int tv)//�����Ϊ��ֵ������Խ��=
	{
		if (tv%temValue == 0)//���tv��temValue�ı���
		{
			return true;

		}
		return false;
	}
	);//��lambda���ʽ����vector������
}

int main(void)
{
	myFunction();
	cout << gv[0](10) << endl;
	/*
	 * gv[0](10)���õ�ʱ��temValue�Ǹ��ֲ������Ѿ������������ˣ��������������
	 * temValue���ڴ�ռ��Ѿ��ͷ��ˡ�����취����Ϊ��ֵ����
	 */
	
	system("pause");
	return 0;
}
/*
* (1)lambda��������_�����б��е�&_�ֲ���������������
* �����ⲿ�����е����б���������Ϊ������lambda���ʽ��ʹ�á�
* �����������ֲ���ʽ���ᵼ��lambda�����󶨵��ֲ������е����á�
* (2)
* (3)
* (4)
* (5)
* (6)(7)
*/