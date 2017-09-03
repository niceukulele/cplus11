#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
#include <algorithm>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

using namespace std;

class background_task {
public:
	void operator()() const {
		cout << "i'm background task" << endl;
		for (int i = 0; i < 30; i++) {
			cout << "count: " << i << endl;
		}
	}
};

class memory_pool {
public:
	memory_pool(size_t size) : m_size(size) {
		ptr = new uint8_t[m_size];
	}	
	virtual ~memory_pool() {
		if (m_thread.joinable())
			m_thread.join();
		delete ptr;
	}
	void stat() {
		cout << "pid = " << getpid() << " tid = " << pthread_self() << endl;
		cout << "ptr = " << reinterpret_cast<void *>(ptr) << endl;
		cout << "size = " << m_size << endl;
	}
	void unittest() {
		m_thread = thread(&memory_pool::stat, this);
	}
private:
	size_t m_size;
	uint8_t *ptr;
	thread m_thread;
};

void double_test(int& a)
{
	a += a;
}

template<typename Iterator, typename T>
struct accumulate_block {
	void operator()(Iterator first, Iterator end, T& result) {
		thread::id my_id(this_thread::get_id());
		result = accumulate(first, end, result);
		cout << "tid:" << pthread_self() << "  ret = " << result << '\n' \
			 << "thread::id: " << my_id << '\n' \
			 << "this_thread::get_id()" << this_thread::get_id() <<endl;
	}
};

template<typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T init)
{
	uint32_t length = distance(first, last);
	if (length == 0)
		return init;
	else
		cout << "length=" << length << endl;
	uint32_t const min_per_threads = 25;
	uint32_t const max_threads = 
			(length + min_per_threads -1)/min_per_threads;
	uint32_t const hardware_threads = thread::hardware_concurrency();
	uint32_t num_threads = 
		min(hardware_threads != 0 ? hardware_threads : 2, max_threads);
	uint32_t block_size = length/num_threads;
	cout << "hardware_theads=" << hardware_threads << '\n' \
		 << "max threads=" << max_threads << '\n' \
		 << "num_threads=" << num_threads << endl;
	vector<T> results(num_threads);
	vector<thread> threads(num_threads-1);
	Iterator block_start = first;
	for (uint32_t i = 0; i < num_threads-1; ++i) {
		Iterator block_end = block_start;
		advance(block_end, block_size);
		threads[i]=thread(accumulate_block<Iterator, T>(), 
						block_start, block_end, ref(results[i]));
		block_start = block_end;
	}
	accumulate_block<Iterator, T>()(
		block_start, last, results[num_threads - 1]);
	for_each(threads.begin(), threads.end(), mem_fn(&thread::join));
	//for_each(threads.begin(), threads.end(), bind(&thread::join(), ))
	return accumulate(results.begin(), results.end(), init);
}
int count1m_test();
#define PARALLEL_ACCUMULATE_TEST
void thread_main_test()
{
	vector<int> a(100, 5);
#if 0
#if defined(MEMORY_POOL_TEST)
	unique_ptr<memory_pool> p_mem(new memory_pool(1024));
	unique_ptr<memory_pool> p2(move(p_mem));
	cout << "p_mem = " << p_mem.get() << endl;
	thread t{bind(&memory_pool::stat, p2.get())};
	if (t.joinable())
		t.join();
	cout << "pid = " << getpid() << " tid = " << pthread_self() << endl;
	cout << "p_mem = " << p_mem.get() << endl;
#elif defined(PARALLEL_ACCUMULATE_TEST)
	cout << "ret=" << parallel_accumulate(a.begin(), a.end(), 0);
#else
	cout << "ret=" << accumulate(a.begin(),a.end(),0);
#endif
#endif
	count1m_test();
}


std::atomic<bool> ready (false);
std::atomic_flag winner = ATOMIC_FLAG_INIT;

void count1m (int id) {
  while (!ready) { std::this_thread::yield(); }      // wait for the ready signal
  for (volatile int i=0; i<1000000; ++i) {}          // go!, count to 1 million
  if (!winner.test_and_set()) { std::cout << "thread #" << id << " won!\n"; }
}

int count1m_test()
{
  std::vector<std::thread> threads;
  std::cout << "spawning 10 threads that count to 1 million...\n";
  for (int i=1; i<=10; ++i) threads.push_back(std::thread(count1m,i));
  ready = true;
  for (auto& th : threads) th.join();

  return 0;
}