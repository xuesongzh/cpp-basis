#pragma once
template<typename T=int,int size=10>
class myArray
{
private:
	T arr[size];
public:
	//���캯��
	myArray();
	//����һ����Ա����
	void myFunction01();
	
};

template <typename T, int size>
void myArray<T, size>::myFunction01()	//��������ֵ ʵ���������ࣺ����������
{
	cout << "����myArray�Ĳ��Ժ���" << endl;
	cout << "size=" << size << endl;
}


//���캯��
template <typename T, int size>
myArray<T,size>::myArray()//���캯���н�ÿ������Ԫ�ص�ֵ������Ϊ0
{
	for (int i=0;i<size;i++)
	{
		arr[i] = 0;
	}
}