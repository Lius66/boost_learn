#include<boost/asio.hpp>
#include<iostream>

void Print(boost::system::error_code ec,
	boost::asio::deadline_timer* timer,
	int* count) {
	if (*count < 3) {
		std::cout << *count << std::endl;
		++(*count);

		timer->expires_at(timer->expires_at() + boost::posix_time::seconds(1));

		timer->async_wait(std::bind(&Print, std::placeholders::_1, timer, count));
	}
}

int main() {
	boost::asio::io_context ioc;
	boost::asio::deadline_timer timer(ioc, boost::posix_time::seconds(1));
	int count = 0;
	timer.async_wait(std::bind(&Print, std::placeholders::_1, &timer, &count));

	ioc.run();
	system("pause");
	return 0;
}