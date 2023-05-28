#pragma warning(disable:4996)

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>

using namespace std;

class String {
    char* str;
    int size;
public:
    String(const char* s, int siz) {
        str = new char[siz];
        strcpy(str, s);
    }

    String(const char* s):String(s,strlen(s)+1) {
        size = strlen(s)+1;
    }

    String() : String("",80) {}
    
    String(String& ss) {
        str = new char[strlen(ss.getStr())+1];
        size = strlen(ss.getStr()) + 1;
    }

    void print() {
        cout << "String: " << str << endl;
        cout << "Size: " << size << endl;
    }

    void setStr(const char* s) {
        delete[] str;
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    const char* getStr() {
        return str;
    }

    ~String() {
        delete[] str;
        cout << "\nDeString\n";
    }
};

int main() {

    setlocale(0, "");
    srand(time(NULL));

    String s{"kek"};
    s.print();
}
