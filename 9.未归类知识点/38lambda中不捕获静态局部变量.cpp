#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;
std::vector<void (*)(int)> gv2;  //���ڴ��һ��int���Ͳ���������ֵ��void���͵�lambda���ʽ

int main(void) {
    static int temvalue = 4;
    gv2.push_back([](int value)  //��̬�ֲ���������ֱ��ʹ��
                  {
                      cout << temvalue << endl;
                      temvalue++;
                  });

    gv2[0](12);   // 4
    gv2[0](123);  // 5
    gv2[0](123);  // 6

    system("pause");

    return 0;
}
/*
 * (1)lambda�в�����̬�ֲ�����
 *	����ʱ���ǲ�������̬�ֲ�������Ҳ����˵��̬�ֲ������ǲ��ܱ������x��
 *	���ǿ�����lambda���ʽ��ʹ�þ�̬�ֲ���������̬�ֲ������Ǳ����ھ�̬�洢����������Ч���ǳ���������ڼ䡣
 *
 *	��̬��������Ҫ����Ҳ���񲻵����������ֶԾ�̬�����밴���ò���Ч�����ơ�
 *
 *	��lambda�������ʽ�����vector�����У�����ʹ���±����
 *
 */