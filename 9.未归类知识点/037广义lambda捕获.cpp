#include<iostream>
#include<iostream>
#include<cstdlib>
#include<functional>
#include <vector>
#include <algorithm>
using namespace std;
//ȫ�ֱ�����ÿ��Ԫ�ض���function��ÿ��Ԫ�ض��ǲ�����int������ֵ��bool����
std::vector<std::function<bool(int)>> gv02;

class AT
{
public:
	int m_temvalue = 7;
	void addItem()
	{
		gv02.push_back(// c++4��������lambda���ʽ�β��б���ʹ��auto
				[abc=m_temvalue](auto tv)//��m_temvalue���Ƶ��հ�������lambda��ʹ�õĶ��Ǹ���
					   //�ȼ���
			//[this](auto tv)
		{
			cout << "m_temvalue=" << abc << endl;//7
			if (tv%abc == 0)//���tv��temValue�ı���
			{
				return true;

			}
			return false;
		}
		);
		/*
		* ���ǻ���Ϊ=�ǰ�ֵ����ʹ�����ܹ����ʳ�Ա����m_temvalue,lambda���ʽ��ʹ�õ���m_temvalue�ĸ�����
		*������������ڵ���lambda֮ǰɾ�������ָ�룬//46�У�����ǣ�
		*m_temvalue=-572662307
		*0
		*Ҳ����lambdaִ�е���ȷ���ȴ����pat�����Ƿ���ڣ����lambda���ʽ�ڶ�����ڵ�ʱ�������ȷִ�С�
		*/

	}
};

int main(void)
{
	AT *pat = new AT();
	pat->addItem();
	delete pat;//ok,������ǰɾ��
	cout << gv02[0](10) << endl;//0
	//delete pat;
	
	system("pause");
	return 0;
}
/*
* (1)����lambda����generalized lambda capture
* c++14�����룬���lambda���ʽ��Ա��������thisָ�����⡣

m_temvalue=7
0
�밴���������. . .

* 
* (3)
* (4)
* (5)
* (6)(7)
*/