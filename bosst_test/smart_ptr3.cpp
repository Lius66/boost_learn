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
	//初始化1：默认初始化智能指针保存一个空指针
	std::shared_ptr<Person> p1;

	//初始化2：标准库make_shared
	//make_shared 传递的构造参数与Person 的某个构造函数匹配
	//Person 2 的引用计数为1 ,p2指向它
	auto p2 = std::make_shared<Person>(2);

	//初始化3 使用neew返回的指针初始化智能指针
	//此种方式必须使用直接初始化
	//Person 3 的引用计数为1 p3指向它
	std::shared_ptr<Person> p3(new Person(3));

	if (!p1)//p1是否指向一个对象
	{
		p1 = p2;//Person 2的引用计数为2 p1,p2 指向它
		p2 = p3;//Person 3 的引用计数为2 p2,p3 指向它
		//Person 2的引用计数为1 p1指向它

		std::cout << "This is person " << (*p1).value << std::endl;
		std::cout << "this is person " << p2->value << std::endl;

		//交换p1 和p2的指针
		//Person 2的引用计数为1，p2指向它
		//Person 3 的引用计数为2 p1和p3指向它；
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
	//由于weak_ptr所指对象可能不存在，所以我们不能用weak_ptr
	//直接访问对象，必须调用lock()若不村子啊，则返回一个空 shared_ptr
	//若存在，则返回weak_ptr所指对象的shared_ptr
	//Person 2 的引用计数为 2 p2和p8指向它
	if (auto p8 = p7.lock())
	{
		std::cout << p7.use_count() << std::endl;

	}

	system("pause");
	return 0;
}