#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

//�ݹ���ֹ����
void myFunction02()
{
	cout << "���������ɣ�������ֹ����" << endl;
}


//����2
template<typename T, typename ...U>
void myFunction02(const T&firstarg, const U&...otherargs)
{
	cout << sizeof...(otherargs) << endl;//sizeof...�ɱ�ε�����
	//ע������ĵݹ����չ��������һ��������Ϊ1+1����ֱ�����Ϊ1+0
	cout << "��һ��������ֵΪ��" << firstarg << endl;
	myFunction02(otherargs...);//��ֻ��һ��������ʱ����Ҫ���еݹ���ֵ����
	
}

void func()
{

	myFunction02(1, 23, 43);//2,������һ������
}

int main(void){
	func();
	system("pause");
	return 0;
}

/*

*(2)�ɱ�κ���ģ���������չ��_һ��������һ���������׽��
*չ������·�ȽϹ̶���һ�㶼��ʹ�õݹ麯���ķ�ʽ��չ��:c
*Ҫ�������ڴ����д��������һ��������չ�������͵ݹ���ֹ������
* һ������+һ������������ʲ�������չ����
void myFunction02(const T&firstarg,const U&...otherargs)
*
*
*(3)
*
*
*/