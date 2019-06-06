#include<iostream>
#include<memory>
class A;
class B;

class A
{
public:
	std::weak_ptr<B> pointer;
	~A()
	{
		std::cout << "class A destructed" << std::endl;
	}
};

class B
{
public:
	std::weak_ptr<A> pointer;
	~B()
	{
		std::cout << "class B destructed" << std::endl;

	}
};
void test01()
{
	std::shared_ptr<A> a = std::make_shared<A>();
	std::shared_ptr<B> b = std::make_shared<B>();
	a->pointer = b;
	b->pointer = a;
}
int main()
{
	test01();
	
	system("pause");
	return 0;
}