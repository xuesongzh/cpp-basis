#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;



int main(void)
{
	vector<int> Number1{ 1,2,3,4,5 };
	auto beg = Number1.begin();
	auto end = Number1.end();
	while (beg!=end)
	{
		cout << *beg << endl;
		Number1.insert(beg, 1000);	//����Ԫ�أ���һ��ΪԪ��λ��,��һ��������λ�ã�2ΪԪ�ص�ֵ
		//�������ᵼ�µ�����ʧЧ�������ĸ�������ʧЧ��ȡ����������ʵ��ԭ�����ǲ�ȥ��ϸ�о��������ǵ���������
		//һ�������ݾ�����break���������½���������������ѭ������
		break;
		++beg;
	}
	//ǰ��������ݣ�����ѭ��������ǰ��ĵ������Ѿ�ʧЧ
	beg = Number1.begin();
	end = Number1.end();
	while (beg != end)
	{
		cout << *beg << endl;
		++beg;
	}


	//�����ʹ��break��������ÿ�θ���end()
	auto beg2 = Number1.begin();
	int iCount = 0;
	while(beg2!=Number1.end())	//ÿ�θ��£�����endʧЧ
	{
		beg2 = Number1.insert(beg2, iCount + 80);//�鿴ÿ�β�����
		iCount++;
		if (iCount>10)
		{
			break;
		}
		++beg2;
	}
	for(beg2=Number1.begin();beg2!=Number1.end();beg2++)
	{
		cout << *beg2 << endl;
	}



	
	system("pause");
	return 0;
}

/*
* (1)
* *()6)������ʧЧ����
*	�ع˷�Χforѭ��--ʹ�õ�����ʵ��
*	�ڲ����������Ĺ����У�ǧ��Ҫ�ı�vector��������������Ҫ���ӻ���ɾ��vector�е�Ԫ�صĸ���
*	���ӻ���ɾ��Ԫ�أ����ֲ������ܵ���ָ�������ĵ�����ʧЧ��ʧЧ�ͱ�ʾ�����ٴ����κ������е�Ԫ�ء�һ��ʹ��ʧЧ�Ķ�����
*	�͵��ڷ���԰�еĳ�������ںܶ�����£������ֱ�ӱ�����list map�ж���˳��洢�ģ������ɾ��Ԫ�ض���Ҫ����
*	�������ɾ���ᵼ�����ֵ�����ʧЧ��
*
*���ѳ�����ʾ1--
*�������ı���Ԫ�صĸ���������break����
*/


