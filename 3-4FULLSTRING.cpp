#pragma warning(disable:4996)

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>

using namespace std;

class String { // 2 задание по классу String
    char* str;
    int size;
    static int count;
public:
    String(const char* str, int size) {
        this->str = new char[size];
        strcpy(this->str, str);
        count++;
    }

    String(const char* str) :String(str, strlen(str) + 1) {
        size = strlen(str) + 1;
    }

    String() : String("", 80) {}

    String(String& ss) {
        str = new char[strlen(ss.getStr()) + 1];
        strcpy(str, ss.getStr());
        size = strlen(ss.getStr()) + 1;
        count++;
    }

    void print() {
        cout << "String: " << str << endl;
        cout << "Size: " << size << endl;
    }

    void setStr(const char* str) {
        delete[] this->str;
        this->str = new char[strlen(str) + 1];
        size = strlen(str) + 1;
        strcpy(this->str, str);
    }

    const char* getStr() {
        return str;
    }
    static int getCount() {
        return count;
    }
    ~String() {
        delete[] this->str;
        //cout << "\nDeString\n";
    }

    String& operator=(const String s2) {
        delete[] str;
        str = new char[strlen(s2.str) + 1];
        strcpy(str, s2.str);
        size = s2.size;
        return *this;
    }
    char operator[](int num) {
        return (char)str[num];
    }
    int operator()(char sym) {
        for (int i = 0; i < size; i++) {
            if (str[i] == sym) {
                return i;
            }
        }
        return -1;
    }
};


int String::count{ 0 };
int main() {

    setlocale(0, "");
    srand(time(NULL));

    String s{ "okay" };
    s.print();
    s.setStr("alright");
    s.print();
    String d{ s };
    d.print();
    cout << "\nCount: " << String::getCount() << endl;
    String f{ "maybe" };
    s = f;
    s.print();
    // задание за 5 число
    cout <<"[]: "  << s[0] << endl;
    cout << "(): " << s('y') << endl;
}
