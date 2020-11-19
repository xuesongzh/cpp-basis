#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include <memory>
#include <list>

using namespace std;


int main(void)
{
	//list<int, std::allocator<int>>myList;
	//2
	list<int>myList;//˫�������ڴ��в�Ҫ������
	myList.push_back(10);
	myList.push_back(20);
	myList.push_back(30);
	myList.push_back(40);
	myList.push_back(50);
	for (auto iter=myList.begin();iter!=myList.end();iter++)
	{
		cout << *iter << endl;
		cout <<&(*iter) << endl;
	}
	/*
	 * 10
004BD648
20
004BD680
30
004BD6B8
40
004BD6F0
50
004BD728
	�ܽ᣺�ڴ治�������ײ㲻��ʹ���ڴ�ؼ���ʵ�֣�������ֱ�ӵ���malloc()����
	 */



	//3��������ʹ��--�Լ�ʵ�ַ�������������ʹ�ã�����c++���Ե�Ҫ��
	allocator<int>aalloc;//����һ��aalloc����������
	int*p = aalloc.allocate(3);//allocate()�Ƿ������е���Ҫ���������ڷ���һ��ԭʼ�ڴ棬
	//����һ���ܱ���3��int���͵Ķ�������Ϊ12�ֽ�
	int*q = p;
	*q = 1;
	q++;
	*q = 2;
	q++;
	*q = 3;
	aalloc.deallocate(p, 3);//deallocate()�Ƿ������е���Ҫ�����������ͷź�����
	//�ͷŵ��׵�ַ�Ͷ���ĸ���
	
	system("pause");
	return 0;
}

/*
*(1)��������һ�㶼����Ҫ�Լ�ָ������һ����ģ�壬���ƶԶ�������ڴ���䡣
list<int, std::allocator<int>>myList;
*��η���С�ڴ棬û�ζ���Ҫ����ܶ��ڴ�����ڴ����Ĺ������������Ƕ��ڴ���䷽�����й������Ч�ʡ�
*�ڴ�ط������Ƿ���һ����ڴ棬ÿ�δ���ȡ��һ�¿�����Ҫ����ڴ档
*
*(2)����allocator�Ƿ�ʹ�����ڴ�ؼ�����
*
*(3)��������ʹ��
*��������һ����ģ�壬ָ������ģ������������Ǽ��ٻ��õ�allocator���������ķ�������
*���Ǵ��﷨�ϣ�allocator���������ܹ�ֱ�ӱ���ʹ�õġ�
*
*(4)�����ķ�������ԭ��˵
*linux GNU
*ʹ���ڴ����ʵ�ַ����������ǽ����ڴ�����Ǹ����ѵġ�
*��ô��������һ��ȫ�ֵķ�������ÿ���������������ɸ��ڴ�أ���ÿ������ģ��ʵ�֡���ϸ��ͼ��
*
*(5)�Զ��������
*	���뷱����������д
*
*	2019��11��28��21:04:30
*	Sunrise �ڶ���������ѧ�ڶ���ѧ¥1121ʵ����
*/