#include <iostream>
#include <string>
#include <mutex>
#include <vector>
#include <memory>

using namespace std;

void foo() ;

void thread_mutex_test()
{
	foo();
}

class some_data {
	int a;
	string b;
public:
	void do_something() {}
};

class data_wrapper {
	some_data _data;
	mutex _lock;
public:
	template<typename FUNC>
	void process_data(FUNC f) {
		lock_guard<mutex> l(_lock);
		f(_data);
		cout << "some_data ptr=" << &_data << endl;
	}
};

some_data *unprotected;
void malicious(some_data& protected_data)
{
	unprotected = &protected_data;
	cout << "unprotected some_data ptr=" << unprotected << endl;
}

mutex a, b;
void foo() 
{
	lock(a, b);
	lock_guard<mutex> ma(a, adopt_lock);
	lock_guard<mutex> mb(b, adopt_lock);
	data_wrapper x;
	x.process_data(malicious);
	unprotected->do_something();
}

class Connection {
public:
	Connection(string name):mName(name) {}
	virtual ~Connection() { cout << "~Connection()" << endl; }
	static Connection* open(string name) {
		cout << "open" << endl;
		if (sInstance == nullptr) {
			sInstance = new Connection(name);
		}
		return sInstance;
	}
	void send() { cout << mName << " send" << endl; }
	void recv() { cout << mName << " recv" << endl; }
private:
	static Connection* sInstance;
	string mName;
};
Connection* Connection::sInstance = nullptr;
#if 0
Connection& Connection::open(string name) {
	cout << "open" << endl;
	if (sInstance == nullptr) {
		sInstance = Connection(name);
	}
	return sInstance;
}
#endif
class B {
public:
	B() { cout << "B()" << endl; }
	virtual ~B() { cout << "~B()" << endl; }
	char b;
};
class ConnectionManager : public B {
public:
	int send(const vector<uint8_t>& dpkg);
	int receive(vector<uint8_t>& dpkg);
	ConnectionManager() { cout << "ConnectionManager()" << endl; }
	virtual ~ConnectionManager() { cout << "~ConnectionManager()" << endl; }
private:
	int open();
	once_flag connect_success;
	shared_ptr<Connection> con;
	//shared_ptr<B> b;
};

int ConnectionManager::open() {
	con = shared_ptr<Connection>(Connection::open("NASA"));
	//b = shared_ptr<B>(new B());
	return 0;
}

int ConnectionManager::send(const vector<uint8_t>& dpkg) {
	call_once(connect_success, &ConnectionManager::open, this);
	con->send();
	return 0;
}

int ConnectionManager::receive(vector<uint8_t>& dpkg) {
	call_once(connect_success, &ConnectionManager::open, this);
	con->recv();
	return 0;
}

void test_entry() {
	vector<uint8_t> a(5,100);
	auto cm = make_shared<ConnectionManager>();
	cm->send(a);
	cm->receive(a);
} 