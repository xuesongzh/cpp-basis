#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;
//ȫ�ֱ�����ÿ��Ԫ�ض���function��ÿ��Ԫ�ض��ǲ�����int������ֵ��bool����
std::vector<std::function<bool(int)>> gv;

class AT {
 public:
    int m_temvalue = 7;
    void addItem() {
        gv.push_back(                  // c++14��������lambda���ʽ�β��б���ʹ��auto
            [abc = m_temvalue](auto tv)  //��m_temvalue���Ƶ��հ�������lambda��ʹ�õĶ��Ǹ���
                                         //�ȼ���
                                         //[this](auto tv)
            {
                cout << "m_temvalue=" << abc << endl;  // 7
                if (tv % abc == 0)                     //���tv��temValue�ı���
                {
                    return true;
                }
                return false;
            });
    }
};

int main(void) {
    AT *pat = new AT();
    pat->addItem();
    delete pat;                   // ok,������ǰɾ��
    cout << gv[0](10) << endl;  // 0
    // delete pat;

    system("pause");
    return 0;
}
/*
* ����lambda����generalized lambda capture
* c++14�����룬���lambda���ʽ��Ա��������thisָ�����⡣

m_temvalue=7
0

*/