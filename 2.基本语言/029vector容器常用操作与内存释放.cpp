#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
//���ڱ��������ļ��Ľṹ��
struct Config
{
	char IterName[128];	//��Ŀ����
	char ItemContent[128];	//��Ŀ����
};
using namespace std;


//����item����content������
char* getInfo(vector<Config*>&conflist,char*pItem)
{
	for (auto pos=conflist.begin();pos!=conflist.end();pos++)
	{
		if (strcmp((*pos)->IterName,pItem)==0)
		{
			return (*pos)->ItemContent;
		}
	}
	return nullptr;
}


int main(void)
{
	Config*pConfig = new Config;
	strcpy_s(pConfig->IterName, sizeof(pConfig->IterName), "ServerName");
	strcpy_s(pConfig->ItemContent, sizeof(pConfig->ItemContent), "1��");

	Config*pConfig2 = new Config;
	strcpy_s(pConfig2->IterName, sizeof(pConfig2->IterName), "ServerID");
	strcpy_s(pConfig2->ItemContent, sizeof(pConfig2->ItemContent), "100000");

	vector<Config*>ConfList;
	ConfList.push_back(pConfig);	//Ԫ��0
	ConfList.push_back(pConfig2);	//Ԫ��1
	/*
	 * ע�⣺�����д洢ָ�����ͣ���ô����ֻ����һ�ݣ���������ʹ��new������ָ�����pConfig pConfig2����������
	 * ��Ԫ��0 Ԫ��1����ָ��ͬһ���ڴ�ռ䡣Ҳ����˵������ָ��ָ��ͬһ���ڴ�ռ䡣
	 */
	//��ô����item���ض�Ӧ��content����
	char*p_Tem = getInfo(ConfList, "ServerName");
	if (p_Tem!=nullptr)
	{
		cout << p_Tem << endl;	//1����
	}

	//������Ҫ�Լ��ͷ��ڴ棬�Լ�new�ľ�Ҫ�Լ��ͷţ�����ͻ�����ڴ�й©
	//ÿ�α���һ�Σ��Ͱ�������Ԫ��ָ����ڴ�ռ��ͷŵ��������е�Ԫ�ز��ͷš�
	for (vector<Config*>::iterator pos=ConfList.begin();pos!=ConfList.end();pos++)	
	{
		delete(*pos);//	�����е�Ԫ�ر�����ָ�룬pos�൱�ڶ���ָ��,����*pos�����Ǹ�ָ��
	}
	ConfList.clear();	//��һ��������û�У�ϵͳϵͳ�����н����Զ��������
	
	system("pause");
	return 0;
}

/*
* (1)ʵ������
* ServerName=1�� ����������
* ServerID=1000 ������ID
*
*  Sunrise�ڶ���������ѧ�ڶ���ѧ¥1121ʵ����
*  2019��11��14��12:07:53
*  
*/