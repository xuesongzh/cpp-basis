#include<iostream>
#include<iostream>
#include<cstdlib>
#include<functional>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

//ȫ�ֱ�����ÿ��Ԫ�ض���function��ÿ��Ԫ�ض��ǲ�����int������ֵ��bool����
std::vector<std::function<bool(int)>> gv02;



class AT
{
public:
	int m_temvalue = 7;
	void addItem()
	{
		auto temvalue02 = this->m_temvalue;//��Ա����ת�ֲ�������lambda���ʽ����
		gv02.push_back(// c++4��������lambda���ʽ�β��б���ʹ��auto
			//[=](auto tv)//��ֵ���񣬽�����ò��񳬳���Χ�����⣨�������գ�=��ֵ���൱����this
			//�ȼ���
			[this](auto tv)
		{
			cout << "m_temvalue=" << m_temvalue << endl;//7
			if (tv%m_temvalue == 0)//���tv��temValue�ı���
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
	//delete pat;
	cout << gv02[0](10) << endl;//0
	delete pat;
	
	system("pause");
	return 0;
}
/*
* (1)lambda��������_�β��б����ʹ��auto
* c++4��������lambda���ʽ�β��б���ʹ��auto��//18��
* (2)lambda��������_���г�Ա������������_ʵ�����ǲ����thisָ��
* ��ȷһ�㣺����������ֻ����ڴ���lambda���ʽ���������ڿɼ��ģ��Ǿ�̬ �ֲ������������βΣ�
* m_temvalue���ǷǾ�̬�ֲ�������m����temvalue��AT��ĳ�Ա��������Ա�������ܱ����񵽵ġ�
* ��ôΪʲô������lambda��ʹ��m_temvalue?
* thisָ��ָ�����������ʹ�õ�[=]�������thisָ��ֵ��
* [=](auto tv)�ȼ���
* [this](auto tv)
* ����취������Ա������ֵ��һ���ֲ������У�����ֲ�������ֵ��
* (3)
* (4)
* (5)
* (6)(7)
*/