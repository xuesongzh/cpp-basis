#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    vector<int> myV;
    myV.push_back(1);
    myV.push_back(2);
    myV.push_back(3);
    vector<int>::size_type mySize = myV.size();
    cout << mySize << endl;                      // 3
    decltype(myV)::size_type mysize02 = mySize;  //抽取myV的类型，
    cout << mysize02 << endl;                    // 3

    typedef decltype(sizeof(0)) size_t;  //等价于size_t是int类型
    /*
     * typedef decltype(sizeof(int)) size_t
     * typedef unsigned int size_t
     */

    system("pause");
    return 0;
}