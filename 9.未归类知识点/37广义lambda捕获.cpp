#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;
//全局变量，每个元素都是function，每个元素都是参数是int，返回值是bool类型
std::vector<std::function<bool(int)>> gv;

class AT {
 public:
    int m_temvalue = 7;
    void addItem() {
        gv.push_back(                  // c++14中允许在lambda表达式形参列表中使用auto
            [abc = m_temvalue](auto tv)  //将m_temvalue复制到闭包中来，lambda中使用的都是副本
                                         //等价于
                                         //[this](auto tv)
            {
                cout << "m_temvalue=" << abc << endl;  // 7
                if (tv % abc == 0)                     //如果tv是temValue的倍数
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
    delete pat;                   // ok,可以提前删除
    cout << gv[0](10) << endl;  // 0
    // delete pat;

    system("pause");
    return 0;
}
/*
* 广义lambda捕获generalized lambda capture
* c++14中引入，解决lambda表达式成员属性依赖this指针问题。

m_temvalue=7
0

*/