#pragma once
#ifndef __MYVECTOR__
#define __MYVECTOR__

//����myvector��
template <typename T>//����ΪT��ģ�������������ʾmyVector���������������
class myVector
{
public:
	//��������
	typedef T* myIterator ;	//�紫�ݹ���int���ͣ�����Ϊint*---�������ͳ�Ա
public:
	myVector();//���캯��
	myVector&operator=(const myVector&my_vector);//��ֵ��������أ������ڲ�ʹ��ģ�����ֲ���Ҫ�ṩģ�����
	//myVector<T>&operator=(const myVector<T>&my_vector);//ok
public:
	myIterator mybegin();//����������ʵλ��
	myIterator myend();//�����������һ��Ԫ�ص���һ��λ��

	void myTestFunctin();
};

//���캯��
template <typename T>
myVector<T>::myVector()
{
	
}

//ʹ��typedef�Զ�������������
template <typename T>
typename myVector<T>::myIterator/*��������ֵ*/     myVector<T>::mybegin()
{
	
}

//ʹ��typedef�Զ�������������
template <typename T>
//typename�÷�2.�������ͳ�ԱmyIterator
//typename ���ô�������ʽ���߱�����myVector<T>::myIterator��һ������
typename myVector<T>::myIterator/*��������ֵ*/     myVector<T>::myend()
{
	
}

//��һ��TҪ����һ��ʵ��������ģ�����ͣ��ڶ���T��ʾ��һ��ʵ��������
template <typename T>
myVector<T>& myVector<T>::operator=(const myVector& my_vector)
{
	
}

template<typename  T>
void myVector<T>::myTestFunctin()
{
	cout<<"���ǲ��Ժ���"	<<endl;
}


#endif
