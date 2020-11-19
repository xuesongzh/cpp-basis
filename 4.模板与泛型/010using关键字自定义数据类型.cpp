#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include <map>

using namespace std;
//���Ѿ�֪�������������������
typedef unsigned int uint;//���޷���������һ������uint
using u_int = unsigned int;

typedef std::map<std::string, int> myMap;
using myMap006 = std::map<std::string, int>;

//����ڿ����ж�������Ͳ��̶�����map�����е�key�̶�������ֵvalue���̶���ʹ��typedef������ɡ�
//c++98��ʹ����ģ����ʵ��
template <typename T>
class map_s
{
public:
	typedef  std::map<std::string, T > mymap02;//�Զ������ͣ���key��string��ֵ��T����
};

//c++11ʵ����������
template<typename T>
using str_map_t = std::map<string, T>;//������ǰ�档
/*�÷���ͨ��using�ؼ��ָ�һ������ģ�������֣������������
 *�÷�2���������ͬ�������������б�¶������
 *�÷�3���������ͣ��纯������ 
 */
//using���庯������
using myFunction = void(*)(int, int);
typedef void(*myFunction02)(int, int);//�ȼ�



//using��ϰ
template<typename T>
using myFunction_m = int(*)(T, T);//����"����ģ��"���Ȳ�����ģ�壬Ҳ���Ǻ���ģ�壬�൱��ģ����ı���

int testFunction(int a,int b)
{
	return  a + b;
}


int main(void)
{
	//(1)
	uint a = 10;
	myMap map1;
	map1.insert({ "aaaa", 1 });
	map1.insert({ "bbbb",2 });

	//key�̶���valueֵ��ȷ��
	map_s<int>::mymap02 map001;
	map001.insert({ "aaaaa",1 });
	map_s<string>::mymap02 map002;
	map002.insert({ "bbbbb","2" });


	//c++11ʵ����������
	str_map_t<int> map003;
	map003.insert({ "dfsdf",3 });


	//using��ϰ
	myFunction_m<int> pointFunc;//���ݺ���ָ�����Ͷ��庯��ָ��
	pointFunc = testFunction;//�Ѻ�����ַ��ֵ������ָ�����
	//pointFunc = &testFunction;//ok
	cout << pointFunc(23, 45) << endl;

	system("pause");
	return 0;
}

/*
*(1)using ����ģ�����
*	1.typedefһ�������������ͱ���
	2.typedef  std::map<std::string, T > mymap02;//�Զ������ͣ���key��string��ֵ��T����
*	3.using���ڶ������ͻ�������ģ�����ʱ�򣬰�����typedef�����й��ܡ�
		����������ͱ���
		��������ģ��
		���庯��ָ��
*
*	2019��11��25��10:28:07
*	 Sunrise�ڶ���������ѧ�ڶ���ѧ¥1121ʵ����

*
*
*/