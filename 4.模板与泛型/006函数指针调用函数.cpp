#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>


using namespace std;
int myFunction(int a,int b)
{
	return  a + b;
}
//�Ѻ���ָ����Ϊ����һ�������Ĳ������ݣ���
//
//����һ������ָ������
typedef int(*FunType)(int, int);
//����һ���������պ�����ָ��
void TestFunction(int i,int j,FunType myfun)
{
	//�������ͨ������ָ����ú���
	int result = myfun(i, j);
	cout << result << endl;
}


int main(void)
{
	TestFunction(1, 2, myFunction);//�������־��൱��һ��������ַ
	TestFunction(1, 2, &myFunction);//ok��ȡ��ַҲ���Ե��óɹ�

	system("pause");
	return 0;
}

/*
*(1)����ָ�������������Ĳ���
*
*
*(2)
*
*(3)
*
*
*/