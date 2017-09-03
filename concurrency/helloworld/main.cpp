#include <map>
#include <iostream>
#include "thread_test.h"
#include "thread_mutex_chapter2.h"

using namespace std;

int map_test()
{
    map<char, int> m;
    m['e'] = 100;
    m['d'] = 300;
    m['+'] = 900;
    m['a'] = 150;
    for (auto it = m.begin(); it != m.end(); ++it) {
	cout << "m[" << it->first << "]=" << it->second << endl;
    }
    return 0;
}

int main(int argc, char** argv)
{
    //std::cout << "Hello World" << std::endl;
    //map_test();
	//thread_main_test();
	//thread_mutex_test();
	test_entry();
	cout << "test over" << endl;
    return 0;
}
