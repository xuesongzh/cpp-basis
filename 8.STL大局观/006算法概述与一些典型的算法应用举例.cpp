#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include <memory>
#include <set>
#include <map>
#include <list>
#include <array>
#include<algorithm>

using namespace std;

//for_eachԴ��ʾ��ͼ
//template<class InputIterator ,class Function>
//Function for_each(InputIterator first, InputIterator end,Function f)
//{
//	for (;first!=end;first++)
//	{
//		f(*first);
//	}
//}
/*
 * ��δ������2������
 *	1.ĳЩ�㷨�������࣬�������������㷨��Ч��
 *	2.f(*first)��һ���ɵ��ö��󣬣��ɵ��ö��������Ҫ����
 */

void myfunc(int i)//�����������е�Ԫ������
{
	cout << i << endl;
}


bool myFunciton06(int i,int j)
{
	return i > j;
}


int main(void)
{

	//��������
	list<int>myList = { 100,300,4,545,4546 };
	list<int>::iterator iterBegin = myList.begin();
	list<int>::iterator iterEnd = myList.end();//���һ��Ԫ�ص���һ��Ԫ��
	//���˼��������㷨�����ݵ���һ��ǰ�պ󿪵�����[iterBegin,iterEnd)
	//�ô����㷨ֻҪ�ж�Ԫ�ص��ں���Ŀ����䣬�ͱ�ʾ��������
	//	2.�����һ���β�==�ڶ����βΣ���ʾ��һ�������䣬-----���һ��Ԫ��λ���൱�ڱ�־��
	//�ܽ᣺��һ�ִ��������ʹ�õ�ȫ�ֺ������㷨�;���������޹ء��㷨�����������û�й�ϵ��ֻ��Ҫ���ݵ����������㷨�������㷨�����ĵ��ԡ�
	//		���ͱ�̷�ʽ����������ԣ�ȱʧ��ֱ���ԡ�
	//		ĳЩ���ݽṹ�������ĵ����������㷨ֱ�ӵļ�����Ҳ����̫�á�


	//for_each()
	vector<int>myVector = { 12,34,34,54,45,454,54,565,6,5 };
	for_each(myVector.begin(), myVector.end(), myfunc);
	//��ÿ��Ԫ��ʹ��myfunc�����������ϵ�������������֮���Ԫ�أ���Ԫ��Ϊʵ�Σ����ú���


	//find()�㷨
	vector<int>myVector02 = { 12,34,34,54,45,454,54,565,6,5 };
	vector<int>::iterator iter04 = find(myVector02.begin(), myVector02.end(), 45);
	if (iter04!=myVector02.end())//�ж��Ƿ��ҵ���Ҫʹ�ã�=�ڶ����������ж�
	{
		cout <<"�Ҵ�Ԫ��"<< *iter04 << endl;
	}
	//����ȫ�ֺ����������ľֲ�����ʱ������ʹ�þֲ����������־ֲ������������Ƚ������Ż�
	map<int, string>myMap;
	myMap.insert(make_pair(1, "aaaa"));
	myMap.insert(make_pair(2, "bbbb"));
	myMap.insert(make_pair(3, "cccc"));
	map<int, string>::iterator iter05 = myMap.find(2);//����ʹ�þֲ�����
	if (iter05!=myMap.end())
	{
		cout << "�ҵ����Ϊ" << iter05->first << "��Ԫ��" << iter05->second << endl;
	}

	auto iter06 = find_if(myVector02.begin(), myVector02.end(), [](int value)
	{
		if (value>15)
		{
			return true;
		}
		return false;
	});//lumbda���ʽҲ��һ���ɵ��ö���
	if (iter06!=myVector02.end())
	{
		cout << "�ҵ�����15��Ԫ�ؽ��Ϊ:" << *iter06 << endl;//34 ֻ���ҵ���һ������������Ԫ��
	}


	//sort()��������
	sort(myVector02.begin(), myVector02.end());//myVector02.begin()+3
	for (vector<int>::iterator iter07=myVector02.begin();iter07!=myVector02.end();iter07++)
	{
		cout << *iter07 << endl;
	}
	//Ĭ���Ǵ�С�������򣬣�Ҫ��Ӵ�С���򣬿���д�Լ���������
	sort(myVector02.begin(), myVector02.end(), myFunciton06);
	for (vector<int>::iterator iter07 = myVector02.begin(); iter07 != myVector02.end(); iter07++)
	{
		cout << *iter07 << endl;
	}
	
	system("pause");
	return 0;
}

/*
*(1)�㷨����  һ����ȫ�ֺ���/ȫ�ֺ���ģ��
*	�㷨��ʵ���Ǻ���ģ�壬������ң�����
*	�㷨��ǰ�����������ͣ�һ���ǵ��������ͣ���ʾ������Ԫ�ص�һ��Ȩ��
*
*(2)�㷨�ڲ��Ĵ���
*	�㷨һ�㴫�������ĵ��������ɡ��㷨���ݴ������ĵ����������������ֵ���������ͬ����������в�ͬ�Ĵ���
*	���ֱ�д��ͬ����������ͬ����ĵ�������Ӱ���㷨��Ч�ʡ�
*	��Ҳ��stl�ڲ�ΪʲôҪ���������з����Ŀ�ġ�
*
*(3)һЩ���͵��㷨ʹ�þ���
*����algorithmͷ�ļ�
*	for_each()
*	find()
*	find_if()
*	sort()
*
*	2019��11��29��09:46:40
*	 Sunrise�ڶ���������ѧ�ڶ���ѧ¥1121ʵ����
*/