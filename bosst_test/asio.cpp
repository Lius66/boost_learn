#include<boost/asio.hpp>
#include<iostream>

void handler(const boost::system::error_code& ec)
{
	std::cout << "5 s." << std::endl;
}

int main()
{
	boost::asio::io_service io_service;   //boost::asio::io_service I/O 服务
	boost::asio::deadline_timer timer(io_service,boost::posix_time::seconds(5));
	//boost::asio::deadline_timer 计时器 用于测量某个固定时间点到来或者一段制定的时长过去了
	//初始化IO对象timer 第一个参数为IO服务 第二个参数指定在某个时间点闹钟定制
	//在timer被定义后开始计时
	timer.async_wait(handler);//调用async_wait()函数并传入handler（)函数的名字作为唯一参数，可以让Asio启动一个异步操作
	//async_wait()的好处是，该函数调用会立刻返回，而不是等待5s。
	//一旦闹钟时间到，作为参数所提供的函数就会被相应调用，因此，应用程序可以在调用async_wait()后执行其他操作而不是阻塞在这里
	io_service.run();

	system("pause");
	return 0;
}