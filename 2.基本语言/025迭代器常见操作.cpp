#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;


struct  Student
{
	int age;
	int number;
};

int main(void)
{
	vector<int>Number1 = { 100,200,300,400 };
	//�������������
	vector<int>::iterator iter;	//	vector<int>::iterator���Ǳ������ͣ�iter�Ǳ������֡�
	//ÿһ�������ж��ᶨ��һ��iterator�ĳ�Ա���ǹ̶���
	//���������ʱ��vector<int>::iterator����һ�����ͣ��������;��ǵ��������͡�������������Ͷ���һ���������ǵ�����

	//������begin() end()����
	iter = Number1.begin();	//�����������Ԫ�أ����ص��ǵ�������ָ�������еĵ�һ��Ԫ�ء�
	//�൱��iterָ����Ϊ0��Ԫ��
	iter = Number1.end();	//���صĲ��������һ��Ԫ�أ��������һ��Ԫ�ص���һ��λ�á����Ϊend()ָ�򲻴��ڵ�һ��λ��

	//�����һ������������ôbegin()��end()���صľ���ͬ��
	vector<int>Number2;
	vector<int>::iterator beginIter = Number2.begin();
	vector<int>::iterator endIter = Number2.end();
	if (beginIter==endIter)	//��֤�ˣ�ָ��ͬһ��λ��
	{
		cout << "����������ָ��ͬһ��λ��" << endl;
	}

	
	//������������е�����
	for (vector<int>::iterator iter2=Number1.begin();iter2!=Number1.end();iter2++)
	{
		cout << *iter2 << endl;	//���������Ե���ָ��������  100 200 300 400
	}

	//������ʣ��ȷ������һ��Ԫ��--���������(���������)
	/*
	 * rbegin()����һ�������������ָ����������ĵ�һ��Ԫ��
	 * rend() ����һ�������������ָ��������������һ��Ԫ�ص���һ��Ԫ��
	 * 
	 */
	//�������Number1�е�����
	for (vector<int>::reverse_iterator rIter3=Number1.rbegin();rIter3!=Number1.rend();rIter3++)
	{
		cout << *rIter3 << endl;	//400 300 200 100
	}

	//�����д洢�ṹ�壬���������---�����Ա
	vector<Student> stuVector;
	Student myStu = { 12,1000 };
	stuVector.push_back(myStu);	//���ƽ������󣬾��������޹صĶ�����ÿ�������Լ����ڴ�
	//����ṹ���е�����
	vector<Student>::iterator iter04 = stuVector.begin();
	cout << (*iter04).number << endl;
	cout << iter04->number << endl;


	//const_iterator������--������������Ϊ����������ʱ�򣬱���ʹ�ó���������
	const vector<int>Number04 = { 0,1,2,3,4 };
	for (vector<int>::const_iterator cIter = Number04.begin();cIter!=Number04.end();cIter++)
	{
		//*cIter = 12;	//�������޸�
		cout << *cIter << endl;	//����������	
	}
	
	//(5)cbegin cend
	for (auto iter05=Number04.cbegin();iter05!=Number04.end();iter05++)
	{
		//*iter05 = 6;//error
		cout << *iter05 << endl;	
	}


	//(6)��ϰ��Χfor����ڲ�����ʹ�õ�����ʵ�ֵ�
	vector<int>Number06 = { 1,2,3,4,5 };
	for (auto x:Number06)
	{
		cout << x << endl;
	}
	//�ȼ��ڵ�����
	for (auto beg=Number06.begin(),end1=Number06.end();beg!=end1;beg++)
	{
		cout << *beg << endl;
	}

	
	system("pause");
	return 0;
}

/*
* (1)���������
*	vector��һ������������������һ�ֱ���������Ԫ�ص��������͡���������������ָ�롣
*	��������������ָ�������е�ĳ��Ԫ�ء�
*
*	��vector��string�п���ͨ���±������[]������Ԫ�أ���ʵ��c++�к���ͨ���±������ʣ�һ��ͨ�������������ʡ�
*	ͨ�������������ǿ��Զ������е�Ԫ��ֵ����string�е�ÿ���ַ����������޸�ĳ����������ָ���Ԫ��ֵ��������Ҳ��++  --�Ȳ���
*	����ʹ�õ����������ʵ������е�Ԫ�ء�
*
*��2�������ĵ���������
*	ÿһ�������ж��ᶨ��һ��iterator�ĳ�Ա���ǹ̶���
*
*	������begin() end() rbegin() rend()����
*		begin() end()���ڷ��ص������ͣ�
*		1.begin()����һ�����������ͣ����Ϊ����һ��������
*		2.end()����ָ�������е��κ�Ԫ�أ��������ʵ�����Ǳ�����á�
*		3.������������е�����for
*
*��3�������������
*	*iter--���ص�����iter��ָ���Ԫ�ص����á�����Ҫ��֤������ָ�������Ч��Ԫ�ء�����ָ��end()
*	++iter  iter++ ������ָ����һ��Ԫ�ء�ָ��end()������++
*	--iter iter--ָ�������е���һ��Ԫ��
*	iter1==iter2 != �ж������������Ƿ����===
*
*��4��const_iterator������--һ���ʾ��������������ʾ����ͨ��������ȥ�޸�������Ԫ�ص�ֵ�������������ָ���ǿ��Ըı�ġ�
*	�о������е�����ָ�롣
*��5��	cbegin() cend()���� ���صĶ��ǳ��������������Ƿ��ǳ��������޹�
*

*	
*	
*/