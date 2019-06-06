#include<iostream>
#include<memory>

void foo(std::shared_ptr<int> i)
{
	(*i)++;
}

int main()
{
	/*auto pointer = std::make_shared<int>(10);
	auto pointer1 = pointer;
	auto pointer2 = pointer;
	int *p = pointer.get();

	std::cout << " pointer.use_count()" << pointer.use_count() << std::endl;
	std::cout << " pointer1.use_count()" << pointer1.use_count() << std::endl;
	std::cout << " pointer2.use_count()" << pointer2.use_count() << std::endl;

	pointer2.reset();

	std::cout << "pointer2.reset():\n";
	std::cout << " pointer.use_count()" << pointer.use_count() << std::endl;
	std::cout << " pointer1.use_count()" << pointer1.use_count() << std::endl;
	std::cout << " pointer2.use_count()" << pointer2.use_count() << std::endl;

	pointer1.reset();
	std::cout << "pointer1.reset():\n";
	std::cout << " pointer.use_count()" << pointer.use_count() << std::endl;
	std::cout << " pointer1.use_count()" << pointer1.use_count() << std::endl;
	std::cout << " pointer2.use_count()" << pointer2.use_count() << std::endl;*/
	/*foo(pointer);
	std::cout << *pointer << std::endl;*/


	std::unique_ptr<int> pointer = std::make_unique<int>(10);
	std::unique_ptr<int>pointer1 ( std::move(pointer));
	//std::cout << *pointer << std::endl;
	if (pointer.get() == NULL)
		std::cout << "pointer has been delete\n";
	std::cout << *pointer1 << std::endl;

	system("pause");
	return 0;
}