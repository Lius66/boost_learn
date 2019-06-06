#include<thread>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<boost/asio.hpp>
#include<boost/bind.hpp>


std::vector<int> fibs(3, 1);
std::vector<int> history_outputs;

boost::asio::io_service io_service;
boost::asio::io_service main_io_service;

void print_fib(const int& num) {
	for (int i = fibs.size(); i <= num; i++)
	{
		fibs.push_back(fibs[i - 1] + fibs[i - 2]);
	}

	main_io_service.post([num]() {
		std::cout << fibs[num] << std::endl;
	});
		
	history_outputs.push_back(fibs[num]);
}
void print_records()
{
	for (auto mem : history_outputs)
		std::cout << mem << std::endl;
}
void run()
{
	io_service.run();
}
int main() {

	boost::asio::io_service::work work(io_service);
	std::thread thread1(run);

	std::string input_str;
	while (std::cin >> input_str) {
		std::transform(input_str.begin(), input_str.end(), input_str.begin(), ::tolower);
		if (input_str == "exit") {
			print_records();
			system("pause");
			return 0;
		}
		else {
			int input_num = std::stoi(input_str);
			//print_fib(input_num);
			/*std::thread thread1(print_fib, input_num);
			thread1.join();*/
			io_service.post(boost::bind(print_fib, input_num));
			//std::thread thread1(run);
			//thread1.join();

			main_io_service.run_one();
		}
	}
	system("pause");
	return 0;
}