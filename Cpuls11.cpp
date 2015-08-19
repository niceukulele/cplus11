//============================================================================
// Name        : Cpuls11.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
void process_value(int& i)
{
    std::cout << "LValue processed" << i << std::endl;
}
void process_value(int&& i)
{
    std::cout << "RValue processed" << i << std::endl;
}
void process_value
int foo()
{
    return -1;
}
#if 1
class MyString {
    char *_data;
    int _len;
    void _init_data(const char *s) {
        _data = new char[_len+1];
        memcpy(_data, s, _len);
        _data[_len] = '\0';
    }
public:
    MyString() {
        _data = NULL;
        _len = 0;
    }
    MyString(const char *s) {
        //assert(s)；
        _len = strlen(s);
        _init_data(s);
    }
    MyString(const MyString& str) {
        _len = str._len;
        _init_data(str._data);
        std::cout << "copy ctor" << std::endl;
    }
    MyString& operator=(const MyString& str) {
        _len = str._len;
        _init_data(str._data);
        std::cout << "copy assign ctor" << std::endl;
        return *this;
    }
    MyString(MyString&& str) {
        _len = str._len;
        _init_data(str._data);
        str._data = nullptr;
        str._len = 0;
        std::cout << "move ctor" << std::endl;
    }
    MyString& operator=(MyString&& str)
    {
        _len = str._len;
        _init_data(str._data);
        str._data = nullptr;
        str._len = 0;
        std::cout << "move assign ctor" << std::endl;
        return *this;
    }
};
#endif
int main(void) {
#if 1
    auto i = 100;
    auto f = 0.11;
	puts("!!!Hello World!!!");
	printf("i=%d, f=%f\n", i, f);
	int a = 0;
	//process_value(a);
	//process_value(3);
	//process_value(foo());
#endif
#if 1
	const int&& t1 = 8;
	int&& t2 = 5;
	//process_value(t1);
	process_value(t2);
	MyString sa;
	sa = MyString("Hello");
	MyString sb(std::move(sa));
	std::vector<MyString> vec;
	vec.push_back(MyString("World"));
#endif
	//std::map<std::string, std::vector<int> > map;
	return EXIT_SUCCESS;
}
