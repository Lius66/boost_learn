#include<boost/asio.hpp>
#include<iostream>
void Print(boost::system::error_code ec) {
	std::cout << "Hello, world!" << std::endl;
}
int main()
{
	boost::asio::io_context ioc;//io_context ���� �����˲���ϵͳ��I/O����
	boost::asio::deadline_timer timer(ioc, boost::posix_time::seconds(3));
	//timer.async_wait(Print);
	timer.wait();
	ioc.run();     //�������� ��ֱ�����е��첽������ɺ� loop�Ž�����run�ŷ���
	system("pause");
	return 0;
}