#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;



int main(void)
{
	vector<int> Number1{ 1,2,3,4,5 };
	auto beg = Number1.begin();
	auto end = Number1.end();


	for (;beg!=end;beg++)
	{
		//Number1.erase(beg);	//�Ƴ�beg������ָ���Ԫ�أ�������һ��Ԫ�ص�λ��
		
	}

	//һ��һ�������ÿ�μ���end()��ֵ--����ʹ��
	vector<int>::iterator iter = Number1.begin();
	while(iter!=Number1.end())
	{
		iter = Number1.erase(iter);
	}

	//��һ��ɾ������--ÿ��ָ��ͷ��ÿ���ж��Ƿ�Ϊ��
	while (!Number1.empty())
	{
		auto iter2 = Number1.begin();
		Number1.erase(iter2);
	}


	
	system("pause");
	return 0;
}

/*
 *��1�����ѳ�����ʾ2
*/


