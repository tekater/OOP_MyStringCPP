#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#include <direct.h>

using namespace std;

class String {
    char* str;
public:
    String() {
        str = nullptr;
    };
    String(const char* str) { 
        this->str = new char[strlen(str)+1];
        strcpy(this->str, str);
    };
    String(const String& s) {
        str = new char[strlen(s.str) + 1];
        strcpy(str, s.str);
    };
    
    int len() {
        int count=0;
        if (str != nullptr) {
            while (str[count] != '\0') {
                count++;
            }
        }
        return count;
    }
    void Clear() {
        if (str != nullptr) {
            delete[] str;
            str = nullptr;
        }
    }

    ~String() {
        Clear();
    }

    String& operator=(const String& s) {
        if (str != nullptr) {
            delete[] str;
        }
        str = new char[strlen(s.str) + 1];
        strcpy(str, s.str);
        return *this;
    };
    String operator+(const String& s) {
        char* copy = new char[strlen(str) + 1];
        strcpy(copy, str);
        return String(strcat(copy,s.str));
    }
    String& operator+=(const String& s) {
        strcat(str, s.str);
        return *this;
    }

    bool operator==(const String& s) {
        return (strcmp(str, s.str) == 0);
    }
    bool operator!=(const String& s) {
        return !(str == s.str);
    }
};

int main()
{
    setlocale(0, "");
    srand(time(nullptr));



}
