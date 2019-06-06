#include<iostream>
#include<memory>

class Person
{
public:
	Person(int v)
	{
		value = v;
		std::cout << "Person " << value << " is constructed" << std::endl;
	}
	~Person()
	{
		std::cout << "Person " << value << "is destructed" << std::endl;
	}
	int value;
};

int main()
{
	//��ʼ��1��Ĭ�ϳ�ʼ������ָ�뱣��һ����ָ��
	std::shared_ptr<Person> p1;

	//��ʼ��2����׼��make_shared
	//make_shared ���ݵĹ��������Person ��ĳ�����캯��ƥ��
	//Person 2 �����ü���Ϊ1 ,p2ָ����
	auto p2 = std::make_shared<Person>(2);

	//��ʼ��3 ʹ��neew���ص�ָ���ʼ������ָ��
	//���ַ�ʽ����ʹ��ֱ�ӳ�ʼ��
	//Person 3 �����ü���Ϊ1 p3ָ����
	std::shared_ptr<Person> p3(new Person(3));

	if (!p1)//p1�Ƿ�ָ��һ������
	{
		p1 = p2;//Person 2�����ü���Ϊ2 p1,p2 ָ����
		p2 = p3;//Person 3 �����ü���Ϊ2 p2,p3 ָ����
		//Person 2�����ü���Ϊ1 p1ָ����

		std::cout << "This is person " << (*p1).value << std::endl;
		std::cout << "this is person " << p2->value << std::endl;

		//����p1 ��p2��ָ��
		//Person 2�����ü���Ϊ1��p2ָ����
		//Person 3 �����ü���Ϊ2 p1��p3ָ������
		p1.swap(p2);
		std::cout << "	p1.swap(p2);\n";
		std::cout << "This is person " << (*p1).value << std::endl;
		std::cout << "this is person " << p2->value << std::endl;

		p1.reset();
		p3.reset();

	}

	auto p4 = std::make_unique<Person>(4);
	std::unique_ptr<Person> p5(new Person(5));

	std::cout << "this is person " << p4->value << std::endl;
	std::cout << "this is person " << p5->value << std::endl;



	std::unique_ptr<Person> p6(p4.release());
	std::cout << "this is person " << p6->value << std::endl;

	std::weak_ptr<Person> p7(p2);
	//����weak_ptr��ָ������ܲ����ڣ��������ǲ�����weak_ptr
	//ֱ�ӷ��ʶ��󣬱������lock()�������Ӱ����򷵻�һ���� shared_ptr
	//�����ڣ��򷵻�weak_ptr��ָ�����shared_ptr
	//Person 2 �����ü���Ϊ 2 p2��p8ָ����
	if (auto p8 = p7.lock())
	{
		std::cout << p7.use_count() << std::endl;

	}

	system("pause");
	return 0;
}