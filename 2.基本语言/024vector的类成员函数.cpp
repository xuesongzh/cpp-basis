#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

int main(void)
{

	//1
	vector<int>Number1;
	if (Number1.empty())
	{
		cout << "Number����Ϊ��" << endl;
	}

	//2
	Number1.push_back(1);
	Number1.push_back(2);
	for (int i=0;i<10;i++)	//vector�п��԰����ظ���Ԫ��
	{
		Number1.push_back(i);
	}
	Number1.push_back(50);

	//3
	cout << Number1.size() << endl;	//13

	//4 clear
	/*Number1.clear();
	cout << Number1.size() << endl;*/

	//5��������Ԫ��
	cout << Number1[3] << endl;	//������Ϊ0��ֵ

	//6
	vector<int>Number2;
	Number2.push_back(2222);
	Number2 = Number1;	//Number2��ԭ����Ԫ�ر�����
	//ʹ��{}���¸�ֵ
	Number2 = { 11,22,33,44 };

	//7
	vector<int>Number3 = Number2;
	if (Number3==Number2)
	{
		cout << "�����������" << endl;
	}


	//8��Χfor���
	vector<int>Number4 = { 1,2,3,4,5,6,7 };
	for (auto& x:Number4)	//����Ҫ�޸�ԭ����ֵ������������
	{
		//��Ϊԭ����2��
		x = 2 * x;	
	}
	for (auto x:Number4)	//�����ǿ�������
	{
		cout << x << endl;
	}
	//��Χfor������
	vector<int>Number5 = { 11,22,33,44 };
	for (auto x:Number5)	//������ʼ�ͼ�¼����λ���ˣ�������ӣ�ɾ��Ԫ�ء�
	{
		Number5.push_back(888);	//�������������������ǰ�����Ԫ���ˣ��ᵼ�´���
		//��һ�е��´���
		cout << x << endl;
	}
	//��Ϊ��һ��ѭ����ʱ�򣬾ͼ�¼�˽�β��ֵ������ѭ�������ʱ���´��󣨲����µ�Ԫ�ص��½�βλ�÷����ı䣩
	/*
	 * ���ۣ���for����У�����һ�������Ĳ����У�ǧ��Ҫ�Ķ�vector���������������ӣ�ɾ��Ԫ�ض�������ִ�С�
	 * ǧ��Ҫ�����ֲ�����
	 */
	system("pause");
	return 0;
}

/*
* (1)vector����Ĳ������������������ǲ�֪��vector�а�������Ԫ�أ���ʹ�ù����ж�̬�Ĵ����ͼ��١�
* ����һ�㶼���ȴ����յ�vector����
* �ܶ������string����
* 
*	1.�ж�vector�Ƿ�Ϊ��.empty()
*	2.push_back()������ĩβ���Ԫ��
*	3.size()����Ԫ�صĸ���
*	4.clear()�����������
*	5.v[n] ���ر��Ϊn��Ԫ�أ���Ŵ�0��ʼ�������±�ķ�Χ��������Ԥ��Ľ��
*	6����ֵ�����=
*	7��ȺͲ���� ��= ==��Ԫ��������ͬ����Ӧλ�õ�Ԫ��Ҳ������ȣ�
*	8.��ΧforӦ��
*/