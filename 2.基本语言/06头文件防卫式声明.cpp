#include <cstdlib>
#include <iostream>

#include "Head.h"
#include "Head2.h"  //Ҫ�Ӻ�����ֹ�ظ���������

using namespace std;

int main006(void) {
    //��Ϊhead2.h������head.h�����Ի�����ض�������
    //������������ #dendef #define

    cout << g_globalh1 << endl;
    cout << g_globalh2 << endl;

    system("pause");
    return 0;
}
/*
* (1)ʹ��#ifndef #define��#endif������ͷ�ļ�����ʽ���
*/