#include<boost/asio.hpp>
#include<boost/array.hpp>
#include<iostream>
enum { BUF_SIZE = 1024 };
void Session(boost::asio::ip::tcp::socket socket)
{
	try 
	{
		while (true)
		{
			boost::array<char, BUF_SIZE> data;

			boost::system::error_code ec;
			std::size_t length = socket.read_some(boost::asio::buffer(data), ec);
			if (ec == boost::asio::error::eof)
			{
				std::cout << "连接被client妥善的关闭了" << std::endl;
			}
			else if (ec)
			{
				throw boost::system::system_error(ec);
			}
			boost::asio::write(socket, boost::asio::buffer(data, length));
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception:" << e.what() << std::endl;
	}
}

int main(int argc, char* argv[])
{
	/*if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <port>" << std::endl;
		return 1;
	}*/

	unsigned short port = std::atoi("8080");

	boost::asio::io_context ioc;

	// 创建 Acceptor 侦听新的连接
	boost::asio::ip::tcp::acceptor acceptor(ioc, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port));

	try {
		// 一次处理一个连接
		while (true) {
			Session(acceptor.accept());
		}
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	system("pause");
	return 0;
}