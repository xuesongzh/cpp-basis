#include<iostream>
#include<cstdlib>

using namespace std;
decltype(auto) myFunction()
{
	int i = 1;
	return i;
}

decltype(auto)myFunciton02()
{
	int i = 1;
	return(i);//����()�ͻ��ɵ��·���һ������ int&,����i�Ǿֲ�������ʹ�ûᵼ�²���Ԥ�ϵĽ����
	
}

int main(void)
{
	//���ڱ�����������
	int number01 = 12;
	const int &reference = 23;
	auto number02 = reference;//const���Ժ����ö�û�д���
	decltype(auto)number03 = reference;//number03=const int& .auto�����Ķ�����const�����ã����ܹ�ͨ��decltype(auto)�����

	//1.3��˵(x)
	int number04 = 234;
	decltype((number04))rere = number04;//rere=int&����

	decltype(myFunction()) number05 = 23;//int����
	int a = 1;
	decltype(myFunciton02())number06 = a;//������ú������ص���int&���ͣ�����i�Ǿֲ�����
	myFunciton02() = 234;//�﷨��û���⣬���Ǿֲ���i�Ѿ���ϵͳ�����ˣ��ᵼ��δԤ�ϵĽ��
	
	system("pause");
	return 0;
}
/*
* (1)decltype����Ҫ��;_decltype(auto)�÷�
*	1.2���ڱ�����������_����const����������
*	1.3��˵(x) ʹ�ò���decltype�ᵼ�·��ؾֲ�����
* (2)decltype�ܽ�
*	
* (3)
* (4)
* (5)
* (6)(7)
*/