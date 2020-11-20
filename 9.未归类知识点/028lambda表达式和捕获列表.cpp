#include <cstdlib>
#include <iostream>

using namespace std;

class CT {
 public:
    int m_i;
    void myFunction(int x, int y) {
        auto mylambda01 = [this]()  //=或者&默认就有this访问
        {
            return m_i;  //因为前面已经有this，访问合法
        };
    }
};

int main(void) {
    auto f = [](int a = 45) -> int  //后置返回类型  ，并且擦拭农户可以有默认值
    { return a + 1; };              //这里必须有分号
    //调用lambda表达式
    cout << f(12) << endl;  // 13

    static int numnber01 = 12;
    auto f1 = []() {
        return numnber01;  //需要捕获前面定义的number01,可以直接捕获静态局变量
    };
    //[&]
    int number02 = 02;
    auto f2 = [&]() {
        number02++;
        return number02;
    };
    cout << f2() << endl;  // 3
    // 2.3 [=]
    auto f3 = [=]() {
        cout << number02 << endl;
        // number02 = 12;//error 不能修改
    };
    // 2.4[this]
    CT ct;
    ct.myFunction(3, 4);

    // 2.5[变量名字1，变量名字2...]
    int number03 = 3;
    auto f4 = [number02]() {
        cout << number02 << endl;
        // cout << number03 << endl;//error
    };
    system("pause");
    return 0;
}

/*lambda表达式和捕获列表
 * (1)c++11中的新特性，也是一种可调用对象
 * lambda表达式，定义了一个匿名函数，并且可以捕获一定范围内的变量。[]--标志是一个lambad表达式
 * 特点：
 *	1.是个匿名函数，也可以理解为“可调用代码单元”，或者“未命名的内联函数”。
 *	2.也有一个返回类型，一个参数列表，一个函数体
 *	3.与函数不同的是，lambda可以在函数内部定义，常规函数不允许。
 *格式：
 *auto[捕获列表](参数列表)->返回类型后置
 *{函数体}
 *这是一个返回类型后置语法，lambda表达式的返回类型后置是强制要求，语法就是这么要求的。
 *因为很多时候lambda表达式返回值特别明显，所以允许lambda表达式返回值类型省略。编译器可以自动推导。
 *
 *lambda表达式参数列表可以有默认值。
 *
 *1.2参数列表中没有参数的时候，参数列表可以省略，甚至()可以省略，如下格式都合法：
 *auto f1=[](){return 1;}
 *auto f2=[]{return 1;}
 *
 *1.3捕获列表[]和函数体{}不能省略。
 *
 *1.4lambda调用方法和普通函数相同，都是使用()这种函数调用运算符。
 *1.5lambda表达式可以不返回任何类型给你，不返回任何类型就是void类型。
 *auto f3=[]{};//ok
 *1.6函数体末尾的分号不能省略。
 * (2)捕获列表[]--通过捕获列表来捕获一定范围内的变量
 *	2.1[]空表示不捕获任何变量,但是不包括静态局部变量。
 *	2.2[&] 表示以"引用"方式捕获外部作用域中的所有变量。
 *	2.3[=]表示以“值传递”的方式捕获外部变量，只能使用，修改不了外部变量。
 *	2.4[this]一般用于类中，捕获当前类中this指针，让lambda表达式有和当前类成员函数具有同样的
 *		访问权限。如果中括号中已经使用&，或者=，就已经默认使用了this，就是让lambda使用当前类中的成员变量。
 *		用在类中定义lambda匿名函数
 *	2.5[变量名字1，变量名字2...]多个变量使用逗号分开，按照值捕获列出的变量，没有列出的变量，不捕获。
 *	2.6[&变量名字1，&量名字2...]用引用捕获多个变量，同时不捕获没有蕾出的变量
 *	2.7[=,&变量名]  按值捕获所有外部变量，同时按应用捕获&列出的变量。=必须写在开头位置，第一个位置表示默认捕获方式。
 *	2.8[&,变量名字] 按引用捕获外部变量，同时按值捕获指定的外部变量。
 *总结：lambda表达式对于外部捕获控制特别细致。
 *
 * (3)
 * (4)
 * (5)
 * (6)(7)
 * 2019年12月11日13点22分
 */