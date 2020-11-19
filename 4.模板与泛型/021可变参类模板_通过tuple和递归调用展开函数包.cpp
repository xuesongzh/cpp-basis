#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<queue>
#include<functional>

using namespace std;

//mycount����ͳ�ƣ�myMaxCount��ʾ��������
template<int mycount,int myMaxCount,typename ...T>
class myclass
{
public:
	static void myFunction02(const tuple<T...>&t)
	{
		cout << "value="<<get<mycount>(t) << endl;
		myclass<mycount + 1, myMaxCount, T...>::myFunction02(t);
		
	}
};


//�ػ��汾���ڽ�������
template<int myMaxCount,typename ...T>
class myclass<myMaxCount,myMaxCount,T...>
{
public:
	static void  myFunction02(const tuple<T...>&t)
	{
		;
	}
};

template<typename ...T>
void myFunction(const tuple<T...>&t)//�ɱ�κ���ģ��
{
	myclass<0, sizeof...(T), T...>::myFunction02(t);
}


int main(void)
{
	//Ԫ��ʾ��
	tuple<float, int, int>mytuple(12.34f, 100, 1);
	cout << get<0>(mytuple) << endl;
	cout << get<1>(mytuple) << endl;


	myFunction(mytuple);
	system("pause");
	return 0;
}

/*
*(1)ͨ��tuple�͵ݹ����չ��������--��ҪЩ����ػ��汾����һ�����Ѷȡ�
*��һ����0��ʼ�ļ�������ÿ�δ���һ��������������+1��һֱ�����в���������ϡ�
*���ʹ��ʹ��һ��ģ��ƫ�ػ�����Ϊ�ݹ���ý�����
*
*(2)
12.34
100
value=12.34
value=100
value=1

*
*(3)�ܽ�
*	��ȡ����������Ĳ�����ʽ�кܶ��֣�����һ���������벻���ݹ������ֶΡ�
*	
*
*
*/