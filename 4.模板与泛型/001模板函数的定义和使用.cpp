#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;
//�����������
int AddFunction(int a,int b)
{
	int Tem = a + b;
	return a + b;
}

int AddFunction(double a,double b)
{
	int tem = a + b;
	return tem;
}

//��������ֻ�в������Ͳ�ͬ
template <typename T>//����һ������ΪT��ģ�庯��
T FunctionTemplate (T a,T b)
{
	T tem = a + b;
	return tem;
}
/*
 * 1.����ģ����template��ͷ����߸�<>��<>�����ģ������б��������ʹ�ö���,�ֿ�
 * 2.<>����������һ��ģ�������ģ�����ǰ���и�typename�ؼ��֣�Ҳ������class,��ʾ�Ǹ���������
 * 3.���ģ������б������ж����������ô��Ҫʹ�ö��typename,class template <typename T��typename Q>
 * 4.ģ������б������ʾ�ں���������Ҫ�õ��ġ����͡����ߡ�ֵ�����뺯�������б����ơ�
 * 5.���õ�ʱ��ʹ��ָ��ģ��ʵ�Σ�ģ������<ģ��ʵ��>������������
 * 6.ģ�庯�����ݵ��ô��ݵ�ʵ�Σ��ڱ����ʱ��ȷ�����͡�
 */

int main(void)
{
	//���������ݵ��õ�ʵ��ȥ�ƶ�ģ�庯������Ĳ������͡���ʱ����Ҫ�ṩ����ʱ���ƶϡ�
	//��ʱ����ݸ���ʵ�����ƶϲ���ģ������ͣ���Ҫʹ��<>�ṩ������
	int Sum = FunctionTemplate<int>(32, 44);
	int Sum02 = FunctionTemplate(44.00, 34.454);//���Բ��ṩģ�����Ͳ���,�������ƶ���double����
	//����ʱ�򣬱����� �ƶϳ�ģ������֮�󣬾�ʵ����һ���ض��汾���͵ĺ�����
	
	
	system("pause");
	return 0;
}

/*
*(1)����ģ��Ķ���
*
*(2)����ģ���ʹ��
*
*(3)
*
*
*/