#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include <memory>
#include<queue>
#include<map>
#include <set>
#include <unordered_set>
using namespace std;

class A
{
public:
	A(int a) :m_i(a)
	{
		cout << "���캯��ִ��" << endl;
	}
	A(const A&a) :m_i(a.m_i)
	{
		cout << "A�Ŀ������캯��ִ��" << endl;
	}

	~A()
	{
		cout << "A����������ִ��" << endl;
	}
public:
	int m_i;
};


int main(void)
{
	deque<A>myDeque;
	for (int i=0;i<5;i++)
	{
		cout << "----------begin------------" << endl;
		myDeque.push_front(A(i));
		cout << "----------end------------" << endl;

	}
	for (int i = 0; i<5; i++)
	{
		cout << "----------begin2------------" << endl;
		myDeque.push_back(A(i));
		cout << "----------end2------------" << endl;

	}
	
	for (int i=0;i<myDeque.size();i++)
	{
		cout << "�±�Ϊi="<<i<<"��ֵΪ"<< myDeque[i].m_i << endl;
		//�����ַ
		printf("ÿ��Ԫ�صĵ�ַΪ:%p\n", &myDeque[i]);
	}
	

	//6
	map<int, string> myMap;
	myMap.insert(make_pair(1, "����"));
	//����2
	myMap.insert(pair<int, string>(2, "�ϰ�"));
	//����
	auto iter02 = myMap.find(1);
	if (iter02!=myMap.end())//���ʹ��first second
	{
		cout << "�ҵ���" << endl;
		cout << iter02->first << iter02->second << endl;
	}


	//7
	set<int>myset;
	myset.insert(1);
	myset.insert(2);
	for (auto iter03=myset.begin();iter03!=myset.end();++iter03)
	{
		cout << *iter03 << endl;
	}

	//8
	cout << "888888888888888888888" << endl;
	unordered_set<int>myUnset;
	cout << "bunket_count=" << myUnset.bucket_count() << endl;//8
	for (int i=0;i<10;i++)
	{
		myUnset.insert(i);
	}
	cout << "bunket_count=" << myUnset.bucket_count() << endl;//64
	//��������������Ԫ���������鿴�����������
	cout << "max_bucket_count=" << myUnset.max_bucket_count() << endl;//536870911
	
	
	system("pause");
	return 0;
}

/*
*(1)deque˫�˶��У����������˽��в����ɾ�� double-ended queue ,�൱�����ζ�̬���飬ͷ����β�����������ٶȿ졣
*	�ܽ᣺�ڲ���ʹ�÷ֶ�����ķ�ʽ�洢��
*(2)stackջ��ֻ��һ�����ڣ����Ƚ������
*vector֧�ִ��м�����ɾ������ȻЧ�ʲ��ߣ�stack��֧�ִ��м�����ɾ��Ԫ�أ�ֻ�ܲ���ջ����Ԫ�ء�
*
*(3)queue ��һ����ͨ���У��ص����Ƚ��ȳ���һ������У�һ�˳����С�
*
*(4)list ˫������������ҪԪ���ڴ���ϵ��һ��
*	����Ч�ʲ�ͻ�������ǲ���Ԫ��Ч�ʸߡ�
*	vector�����ȡԪ�أ��������list�졣
*
*(5)����
*Forword-list��������*(����list)��c++11�±�׼������
*	ֻ����һ���������
*
*(6)map��������
*�ڲ���ʵ�����ݽṹ��Ϊ�������
*���������������в������ݵ�ʱ�򣬲���Ҫ����ָ������λ�ã��������Զ���������λ�á�
*(key, value),ͨ��key��value�ر�졣map������key��ͬ������multimap������ͬ
*
*(7)set���ϲ����ڼ�ֵ�Ե�˵�������Զ�������һ�����ϣ�Ԫ��ֵ�����ظ���������ظ�����ʹ��multiset
*	1.����ʱ����ΪҪ�������Բ����ٶȿ����������ǲ����ٶȿ졣
*	һ��ʹ����ʵ��
*	
*(8)unordered_set unordered_multiset unordered_map  unordered_mulmap
*������hash_map hash_multimap  hash_set hash_multiset�ȶ����Ƽ�ʹ��
*���������ڲ�һ��ʹ�ù�ϣ��ʵ��
*
*
*ɢ�б�Hash table��Ҳ�й�ϣ�����Ǹ��ݹؼ���ֵ(Key value)��ֱ�ӽ��з��ʵ����ݽṹ��Ҳ����˵��
*��ͨ���ѹؼ���ֵӳ�䵽����һ��λ�������ʼ�¼���Լӿ���ҵ��ٶȡ����ӳ�亯������ɢ�к�����
*��ż�¼���������ɢ�б�������M�����ں���f(key)������������Ĺؼ���ֵkey��
*���뺯�������ܵõ������ùؼ��ֵļ�¼�ڱ��еĵ�ַ����Ʊ�MΪ��ϣ(Hash����
*����f(key)Ϊ��ϣ(Hash) ������

2019��11��28��20:29:41
 Sunrise�ڶ���������ѧ�ڶ���ѧ¥1121ʵ����
*()()()()()()
*/