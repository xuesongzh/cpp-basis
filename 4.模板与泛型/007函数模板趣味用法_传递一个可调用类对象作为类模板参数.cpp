#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

int myFunction(int a, int b)
{
	return  a + b;
}


//�Ѻ���ָ����Ϊ����һ�������Ĳ������ݣ���
//
//����һ������ָ������
typedef int(*FunType)(int, int);

template <typename T,typename F>
void testFunction(const T&i,const T&j,F myfunc)
{
	cout << myfunc(i, j) << endl;
}

class tc
{
public:
	tc()
	{
		cout << "�޲ι��캯��ִ��" << endl;
	}
	tc(const tc&t)
	{
		cout << "�������캯��ִ��" << endl;
	}
	//����()�������������
	int operator()(int a,int b)
	{
		return a + b;
	}
public:
	
};



int main(void)
{
	testFunction(1, 2,myFunction);//�Զ��ƶ� TΪint��FΪ��������


	tc object01;
	testFunction(3, 4, object01);
	/*
	 * 1.���ȵ��ÿ������캯��ִ�У���һ��object01�������β�,�ж�Ϊ�� ����
	 * 2.Ȼ��������صĺ�������()�����
	 */
	cout << "_______________________________" << endl;
	testFunction(5, 6, tc());//ʹ��һ����ʱ�����ٵ���һ���������캯����ֻ�������޲ι��캯��

	
	system("pause");
	return 0;
}

/*
 *����һ���ɵ����������Ϊ��ģ�����
 *
*(1)�ɵ��ö������--�������δ����֪ʶ��1��
*	1.����������˺��������������Ҳ����������������������ǿ�����ʹ�ú���һ��ʹ�ø���Ķ���
*		���ǰ�������������Ϊ��������function object��
*	2.C++�������м��ֿɵ��ö��󣺺���������ָ�롢lamba���ʽ��
*		bind�����Ķ����Լ������˺�����������ࡣ
*
*(2)
*
*(3)
*
*
*/