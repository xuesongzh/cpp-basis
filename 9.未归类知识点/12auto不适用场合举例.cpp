#include <boost/type_index.hpp>
#include <cstdlib>
#include <iostream>

using namespace std;

//显示参数类型，这里不研究boost库
template <typename T>
void myFunction01(T& tem) {
    using boost::typeindex::type_id_with_cvr;
    cout << "T type=" << type_id_with_cvr<T>().pretty_name() << endl;                //显示T类型
    cout << "tem type=" << type_id_with_cvr<decltype(tem)>().pretty_name() << endl;  //显示tem类型
}

class TescClass {
 public:
    // auto m;//普通成员变量不可以是auto
    static const auto m2 = 23;  // static const 静态成员可以使用auto，其值必须在类内初始化
};

int main(void) {
    system("pause");
    return 0;
}
/*
 * auto不适用场合举例
 *	1.atuo不能使用于函数形参，比如void myfunction(auto x)
 *	2.类中普通成员变量不能使用auto ，static const 允许，但是必须在类内初始化
 *
 */