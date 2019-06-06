#include<boost/asio.hpp>
#include<iostream>
void Print(boost::system::error_code ec) {
	std::cout << "Hello, world!" << std::endl;
}
int main()
{
	boost::asio::io_context ioc;//io_context 对象 代表了操作系统的I/O服务
	boost::asio::deadline_timer timer(ioc, boost::posix_time::seconds(3));
	//timer.async_wait(Print);
	timer.wait();
	ioc.run();     //阻塞调用 ，直到所有的异步操作完成后 loop才结束，run才返回
	system("pause");
	return 0;
}