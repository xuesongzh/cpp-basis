#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class GrandFather1 {
 public:
    int myValueGrand;

 public:
    GrandFather1(int i) : myValueGrand(i) {}
    virtual ~GrandFather1() {
        cout << "GrandFather1的析构函数执行" << endl;
    }
    void myInfo() {
        cout << "我是GrandFather1" << myValueGrand << endl;
    }
};

class GrandFather2 {
 public:
    int myValueGrand2;

 public:
    GrandFather2(int i) : myValueGrand2(i) {}
    virtual ~GrandFather2() {
        cout << "GrandFather2的析构函数执行" << endl;
    }
    void myInfo() {
        cout << "我是GrandFather2" << endl;
    }
};

//定义父类
class Father : public GrandFather1 {
 public:
    int myValueFather;

 public:
    Father(int i, int k) : GrandFather1(i), myValueFather(k) {
        ;
    }
    virtual ~Father() {
        cout << "这是Father类的析构函数" << endl;
    }
    void myInfo() {
        cout << "我是Father" << endl;
    }
};

class Son : public Father {
 public:
    int myValueSon;

 public:
    Son(int i, int j, int k) : Father(i, j), myValueSon(k) {
    }
    virtual ~Son() {
        cout << "这是son类的洗头函数" << endl;
    }
    void myInfo() {
        cout << "我是son" << endl;
    }
};
//类Father02同时继承两个GrandFather类

class Father2 : public GrandFather1, public GrandFather2 {
 public:
    int myVlaueFather02;

 public:
    Father2(int i, int j, int k) : GrandFather1(i), GrandFather2(j), myVlaueFather02(k) {}
    virtual ~Father2() {
        cout << "这是类Father02类的析构函数" << endl;
    }
    void myInfo() {
        cout << "我是Father02,继承自两个Grandfather1，02" << endl;
    }
};

class Son2 : public Father2 {
 public:
    int myValueSon02;

 public:
    Son2(int i, int j, int k, int m) : Father2(i, j, k), myValueSon02(m) {
        ;
    }
};

int main(void) {
    Father2 myfather(1, 2, 3);         //先调用两个GrandFather的构造函数
    myfather.myInfo();                 //调用Father2类的函数
    myfather.GrandFather2::myInfo();  //调用父类的myInfo函数

    system("pause");
    return 0;
}

/*
*(1)多重继承
*如果从多个父类继承产生子类叫多重继承。
*c继承自B，B继承自A，那么叫多层继承。C-->B-->A
*
*
*(2)继承关系
*son-->Father-->Grandfather1
*
*son2-->Father2-->GranFather1,GrandFather2
*
*
*
*
*/