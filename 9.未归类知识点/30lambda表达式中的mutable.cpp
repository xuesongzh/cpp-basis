#include <cstdlib>
#include <iostream>

using namespace std;

int main(void) {
    int x = 10;
    auto f1 = [=]() mutable  //����mutable���Ը���x��ֵ����Ȼ�ǰ�ֵ�����x
    { x = 234; };

    system("pause");
    return 0;
}
/*
 * (1)lambda���ʽ�е�mutable
 * mutable���׸ı�ģ��ױ��
 * �����ǲ���һ��const���Եı���������mutable�Ϳ����޸�����ֵ��
 */