#include <cctype>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
    string str("jisuanjizuochegnyuanli");
    for (auto iter = str.begin(); iter != str.end(); iter++) {
        *iter = std::toupper((*iter));
    }
    cout << str << endl;

    system("pause");
    return 0;
}
