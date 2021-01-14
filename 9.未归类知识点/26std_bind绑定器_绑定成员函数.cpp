#include <cstdlib>
#include <functional>
#include <iostream>

using namespace std;

class CT {
 public:
    void myFunction(int x, int y) {
        cout << "x=" << x << endl;
        cout << "y=" << y << endl;
        m_a = x;
    }

 public:
    int m_a = 0;
};

int main(void) {
    CT ct;
    auto bf1 = std::bind(&CT::myFunction, ct, std::placeholders::_1, std::placeholders::_2);
    bf1(1, 2);
    /*
     * bind中使用第二个参数ct会导致调用CT的拷贝构造函数来生成一个临时对象，作为std::bind()的
     * 返回值（仿函数类型），后续的myFunction调用修改的是这个临时对象的m_a的值，并不影响ct对象的值。
     * 解决办法：ct使用引用，就不会生成临时对象，会修改真正ct的值
     *
     */
    auto bf2 = std::bind(&CT::myFunction, &ct, std::placeholders::_1, std::placeholders::_2);
    bf2(1, 2);

    system("pause");
    return 0;
}
