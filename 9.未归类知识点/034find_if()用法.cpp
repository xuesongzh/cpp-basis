#include<iostream>
#include<cstdlib>
#include<functional>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	vector<int>myVector = { 10,20,30,40 };
	auto result = find_if(myVector.begin(), myVector.end(), [](int value)
	{
		cout << "value=" << value << endl;
		if (value>20)
		{
			return true;//����trueֹͣ������
		}
		return false;//ֻҪ����false��һֱ�������������Ϊֹ��һֱ������true���߱������λ��
		//find_if��������������ɵ��ö��󷵻�true��find_if��ֹͣ������
		//find_if����һ����������ָ���һ������������Ԫ�أ����������������Ԫ�أ��������������ָ��myVector.end()
	});
	system("pause");
	return 0;
}
/*
* (1)find_if()
* ����ģ�壬���������ң����յ��������������ĺ����������
* 
* (2)�ܽ᣺��ѧϰ����д�Ĵ���ѧϰfind_if()�÷�
* 
* (3)
* 
* (4)
* 
* (5)
* 
* (6)
* 
* (7)
*/