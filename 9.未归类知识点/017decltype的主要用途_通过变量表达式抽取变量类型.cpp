#include<iostream>
#include<cstdlib>
#include <vector>

using namespace std;


int main(void)
{
	//2.2decltype����Ҫ��;_ͨ���������ʽ��ȡ��������
	vector<int> myV;
	myV.push_back(1);
	myV.push_back(2);
	myV.push_back(3);
	vector<int>::size_type mySize = myV.size();
	cout << mySize << endl;//3
	decltype(myV)::size_type mysize02 = mySize;//��ȡmyV�����ͣ�
	cout << mysize02 << endl;//3

	typedef decltype(sizeof(0)) size__t;//�ȼ���size__t��int����
	/*
	 * typedef decltype(sizeof(int)) size__t
	 * typedef unsigned int size__t
	 */

	system("pause");
	return 0;
}
/*
* 2.2decltype����Ҫ��;_ͨ���������ʽ��ȡ��������
*
*/