#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

int main(void)
{
	string s1;
	if(s1.empty())	//	�ж��ַ���Ϊ��
	{
		cout << "s1�ַ���Ϊ��" << endl;
	}


	string s2 = "�Ұ��й�";
	cout << s1.size() << endl;	//0
	cout << s2.size() << endl;	//8
	cout << s2.length() << endl;	//8
	//3
	string s3 = "jisuanjizuchengyaun";
	if (s3.size()>3)
	{
		cout << s3[4] << endl;
		s3[4] = '*';
		cout << s3[4] << endl;	//���޸ĳɹ�
	}

	//4�ַ�������
	string s4 = "12345";
	string s5 = "abcdef";
	string s6 = s4 + s5;
	cout << s6 << endl;	//12345abcdef

	//5�ַ�����ֵ
	string s7 = "123";
	string s8 = "abc";
	s7 = s8;
	cout << s7 << endl;	//abc

	//6�ж��ַ����Ƿ����
	if (s7==s8)
	{
		cout << "s7==s8" << endl;	//������ǰ����и�ֵ��
	}

	//c�����е��ϴ��뾫������Ҫ��ôת��
	string  s9 = "abcde";
	string s10 = "abCde";
	const char*p = s10.c_str();	//pָ���ַ�������ʼλ�õ�ָ��
	char str[128]={0};
	strcpy_s(str, sizeof(str), p);
	cout << str << endl;	//abCde

	//��c�������͵��ַ�����ת��Ϊc++���Ե��ַ�����ʽ
	string s11(str);


	//9��дstring����
	/*string s12;
	cin >> s12;
	cout << s12 << endl;*/

	//10.����ֵ��string���
	string s13 = "123";
	string s14 = "abc";
	string s15 = s13 + " and " + s14;
	cout << "s15=" << s15 << endl;
	//string s16 = "fsdf" + "fsdffsdf";	//	�﷨�ϲ�����������������ӣ���Ϊ��֪��ת����ʲô����Ĭ�����ͣ�������һ�������ͣ�
	//������ԡ�
	string s16 = "fsdf" + s15 + "fsdffsdf";	//ok
	//string s16 = "fsdf" + "fsdffsdf" + s15;	//error


	//striing �еķ�Χfor
	string s17 = "jisuanjizuchengyaunli";
	for (auto x:s17)	//auto���������Զ��ƶ�
	{
		cout << x << endl;	//���ÿһ���ַ���Ȼ����
	}
	for(auto&c:s17)
	{
		c = toupper(c);	//������Сд��ĸת���ɴ�д
	}
	cout << s17 << endl;
	system("pause");
	return 0;
}

/*
* (1)string����ĳ��ò���
*		1.�ж��Ƿ�Ϊ��.empty()
*		2.size() length() �����ֽڣ��ַ������������ַ����ĳ���
*		3.s[n] ����s�еı��Ϊn���ַ���λ�ô�0��ʼ��ţ���size()-1,��������˷�Χ�����ݣ�
*			���߱�����һ���մ�����s[n]ȥ���ʣ���������Ԥ��Ľ��
*		4.s1+s2��ʾ�ַ������ӣ��������Ӻ�Ľ������ʵ����һ���µ�string����
*		5.s1=s2 �ַ�������ĸ�ֵ����s2���ݵĴ���s1�е�����
*		6.s1==s2 �ж������ַ����Ƿ���ȣ������ַ����Դ�Сд�ַ����У���д�ַ���Сд�ַ��ǲ�ͬ���ַ���
*		7.s1!=s2 s1������ s2
*		8.s.c_str()����һ���ַ���s�е�����ָ�롣����һ��ָ��c�ַ�����ָ�볣����Ҳ������\0��β�ġ�
*			���������������Ϊ����c���Լ��ݣ���c������û��string���ͣ���������ͬ��string������c_str()
*			��Ա������string����ת����c�����е��ַ�����ʽ��
*			c---const
*
*		9.��дstring����
*		10.����ֵ��string���
*
*		11.��Χfor������stringʹ�ã�c++11���ṩ�˷�Χfor���
*			�������ʷ�Χfor�е�����Ԫ��
*		
*/