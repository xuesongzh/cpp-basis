#include<iostream>
#include<cstdlib>
#include <functional>

using namespace std;

//��ͨ�����ɵ��ö���
void myFunciton(int value)
{
	cout << "myFunciton����ִ����" << endl;
}

class CB
{
private:
	std::function<void()>fcallBack;
	
public:
	CB(const std::function<void()>&f):fcallBack(f)//����
	{
		int i = 1;
	}
	//���ûص������ĳ�Ա����
	void runCallBack(void)
	{
		fcallBack();
	}
};

class CT
{
public:
	void operator()(void)//���غ������������
	{
		cout << "CT��operator����ִ��" << endl;
	}
};
int main(void)
{
	//С������ʾ
	CT ct;//�ɵ��ö���
	CB cb(ct);//cb��Ҫ�ɵ��ö��������������죬ct��Ϊ��operator()���Կ���ת��Ϊstd::function<void()>&����
	cb.runCallBack();//����CT�е�operator()����

	system("pause");
	return 0;
}
/*
* (1)function()�ɵ��ö����װ��_������ʾ1
* 
	CT��operator����ִ��
	�밴���������. . .

*
*
*/