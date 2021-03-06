
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Human {
 public:
    int age;
    string name;

 public:
    //构造函数
    Human();
    Human(int age, string name);
    //析构函数
    ~Human() {
        cout << "Human析构函数" << endl;
    }

 public:
    virtual void eat() = 0;
};

class Man : public Human {
 public:
    Man();
    virtual void eat() override;

 public:
};

class Woman : public Human {
 public:
    Woman();
    virtual void eat() override;

 public:
};

Woman::Woman() {
    cout << "这是woman的构造函数" << endl;
}

Human::Human() {
    cout << "Human默认构造函数" << endl;
}

Human::Human(int age, string name) {
    this->age = age;
    this->name = name;
}

Man::Man() {
    cout << "Man类的默认构造函数" << endl;
}

void Woman::eat() {
    cout << "Woman类的eat()执行" << endl;
}
void Man::eat() {
    cout << "Man类的eat()执行" << endl;
}

void playObject() {
    Human *p_human01 = new Woman;
    p_human01->eat();  //调用Woman的eat()函数

    Human *p_human02 = new Man;
    p_human02->eat();  //调用Man的eat()函数
}

int main(void) {
    playObject();

    system("pause");
    return 0;
}
/*(1)纯虚函数 - 在基类中定义的 函数返回值  函数名字（函数参数） = 0
 *子类必须实现所有的纯虚函数
 *一旦父类有纯虚函数，那么就不能生成父类的实例化对象。主要用于当成基类生成子类用的。
 *因为父类不能实例化对象，所以父类的纯虚函数也就没有办法调用。
 *
 */
