#include<iostream>

#include<thread>
#include<chrono>

//void f1()
//{
//	std::cout << "f1 running ...\n";
//	std::this_thread::sleep_for(std::chrono::seconds(1));
//}
void foo()
{
	// simulate expensive operation
	std::this_thread::sleep_for(std::chrono::seconds(1));
}

void bar()
{
	// simulate expensive operation
	std::this_thread::sleep_for(std::chrono::seconds(1));
}
int main()
{

	std::thread t1(foo);
	std::thread t2(bar);

	std::cout << "thread 1 id: " << t1.get_id() << std::endl;
	std::cout << "thread 2 id: " << t2.get_id() << std::endl;

	std::swap(t1, t2);

	std::cout << "after std::swap(t1, t2):" << std::endl;
	std::cout << "thread 1 id: " << t1.get_id() << std::endl;
	std::cout << "thread 2 id: " << t2.get_id() << std::endl;

	t1.swap(t2);

	std::cout << "after t1.swap(t2):" << std::endl;
	std::cout << "thread 1 id: " << t1.get_id() << std::endl;
	std::cout << "thread 2 id: " << t2.get_id() << std::endl;

	t1.join();
	t2.join();
	/*std::cout << "starting first helper...\n";
	std::thread helper1(foo);

	std::cout << "starting second helper...\n";
	std::thread helper2(bar);

	std::cout << "waiting for helpers to finish..." << std::endl;
	helper1.join();
	helper2.join();

	std::cout << "done!\n";*/

	/*std::thread t1;
	std::cout << "befor start :joinable: " << t1.joinable() << "\n";
	t1 = std::thread(f1);
	std::cout << "after start :joinable: " << t1.joinable() << "\n";
	t1.join();*/

	std::cout << "main thread...\n";
	system("pause");
	return 0;
}