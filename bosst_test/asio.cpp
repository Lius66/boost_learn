#include<boost/asio.hpp>
#include<iostream>

void handler(const boost::system::error_code& ec)
{
	std::cout << "5 s." << std::endl;
}

int main()
{
	boost::asio::io_service io_service;   //boost::asio::io_service I/O ����
	boost::asio::deadline_timer timer(io_service,boost::posix_time::seconds(5));
	//boost::asio::deadline_timer ��ʱ�� ���ڲ���ĳ���̶�ʱ��㵽������һ���ƶ���ʱ����ȥ��
	//��ʼ��IO����timer ��һ������ΪIO���� �ڶ�������ָ����ĳ��ʱ������Ӷ���
	//��timer�������ʼ��ʱ
	timer.async_wait(handler);//����async_wait()����������handler��)������������ΪΨһ������������Asio����һ���첽����
	//async_wait()�ĺô��ǣ��ú������û����̷��أ������ǵȴ�5s��
	//һ������ʱ�䵽����Ϊ�������ṩ�ĺ����ͻᱻ��Ӧ���ã���ˣ�Ӧ�ó�������ڵ���async_wait()��ִ��������������������������
	io_service.run();

	system("pause");
	return 0;
}