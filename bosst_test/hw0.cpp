#include<thread>
#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<boost/asio.hpp>
#include<boost/bind.hpp>
#include<boost/lexical_cast.hpp>
#include<boost/algorithm/string/case_conv.hpp>

std::vector<long> fibs(3, 1);
std::vector<long> history_outputs;

boost::asio::io_service io_service;
boost::asio::io_service main_io_service;

void print_fib(const int& num)
{
	for (int i = fibs.size(); i <= num && fibs[i - 1] <= LONG_MAX - fibs[i - 2]; i++)
	{
		fibs.push_back(fibs[i - 1] + fibs[i - 2]);
	}
	if (fibs.size() > num)
	{
		main_io_service.post([num]()
		{
			std::cout << fibs[num] << std::endl;
		});
		history_outputs.push_back(fibs[num]);
	}
	else
	{
		main_io_service.post([num]()
		{
			std::cout << "out of range" << std::endl;
		});
	}
}
void print_records() {
	for (auto mem : history_outputs)
		std::cout << mem << std::endl;
}
void run() {
	io_service.run();
}
int main() {

	std::unique_ptr<boost::asio::io_service::work> work = std::make_unique<boost::asio::io_service::work>(io_service);
	boost::asio::io_service::work work1(main_io_service);
	std::thread thread1(run);
	std::string input_str;
	while (std::cin >> input_str) {
		//	std::transform(input_str.begin(), input_str.end(), input_str.begin(), ::tolower);
		boost::to_lower(input_str);
		if (input_str == "exit") {
			print_records();
			//fibs.clear();
			//history_outputs.clear();
			break;
		}
		else {
			try {
				int input_num = boost::lexical_cast<int>(input_str);
				if (input_num < 0)
				{
					std::cout << "illegal input" << std::endl;
					continue;
				}
				io_service.post(boost::bind(print_fib, input_num));
			}
			catch (boost::bad_lexical_cast& e) {
				std::cout << e.what() << std::endl;
				continue;
			}

			/*try {
				int input_num = std::stoi(input_str);
				if (input_num < 0)
				{
					std::cout << "illegal input" << std::endl;
					continue;
				}
				io_service.post(boost::bind(print_fib, input_num));

			}
			catch (std::invalid_argument& e) {
				std::cout << e.what() << std::endl;
				continue;
			}
			catch (std::out_of_range& e){
				std::cout << e.what() << std::endl;
				continue;
			}*/

			main_io_service.run_one();

		}

	}
	work.reset();
	thread1.join();
	return 0;
}