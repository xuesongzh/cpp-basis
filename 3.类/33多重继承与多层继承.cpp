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
        cout << "GrandFather1����������ִ��" << endl;
    }
    void myInfo() {
        cout << "����GrandFather1" << myValueGrand << endl;
    }
};

class GrandFather2 {
 public:
    int myValueGrand2;

 public:
    GrandFather2(int i) : myValueGrand2(i) {}
    virtual ~GrandFather2() {
        cout << "GrandFather2����������ִ��" << endl;
    }
    void myInfo() {
        cout << "����GrandFather2" << endl;
    }
};

//���常��
class Father : public GrandFather1 {
 public:
    int myValueFather;

 public:
    Father(int i, int k) : GrandFather1(i), myValueFather(k) {
        ;
    }
    virtual ~Father() {
        cout << "����Father�����������" << endl;
    }
    void myInfo() {
        cout << "����Father" << endl;
    }
};

class Son : public Father {
 public:
    int myValueSon;

 public:
    Son(int i, int j, int k) : Father(i, j), myValueSon(k) {
    }
    virtual ~Son() {
        cout << "����son���ϴͷ����" << endl;
    }
    void myInfo() {
        cout << "����son" << endl;
    }
};
//��Father02ͬʱ�̳�����GrandFather��

class Father2 : public GrandFather1, public GrandFather2 {
 public:
    int myVlaueFather02;

 public:
    Father2(int i, int j, int k) : GrandFather1(i), GrandFather2(j), myVlaueFather02(k) {}
    virtual ~Father2() {
        cout << "������Father02�����������" << endl;
    }
    void myInfo() {
        cout << "����Father02,�̳�������Grandfather1��02" << endl;
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
    Father2 myfather(1, 2, 3);         //�ȵ�������GrandFather�Ĺ��캯��
    myfather.myInfo();                 //����Father2��ĺ���
    myfather.GrandFather2::myInfo();  //���ø����myInfo����

    system("pause");
    return 0;
}

/*
*(1)���ؼ̳�
*����Ӷ������̳в�������ж��ؼ̳С�
*c�̳���B��B�̳���A����ô�ж��̳С�C-->B-->A
*
*
*(2)�̳й�ϵ
*son-->Father-->Grandfather1
*
*son2-->Father2-->GranFather1,GrandFather2
*
*
*
*
*/