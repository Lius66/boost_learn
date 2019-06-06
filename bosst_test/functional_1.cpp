#include<iostream>
#include<string>
#include<functional>

double f(int x, char y, double z) 
{
	return x + y + z;
}

void print_num(int num)
{
	std::cout << num << std::endl;//打印int数据
}

struct Dog
{
	int m_id;
	explicit Dog(int id) :m_id(id) {}//有参初始化
	void print_add(int i)const
	{
		std::cout << m_id + i << std::endl;
	}
};

//仿函数
class PrintString
{
public:
	void operator()(std::string&& s)const
	{
		std::cout << s << std::endl;
	}
};

class TestClass
{
public:
	int class_member(int a) { return a; }
	static int satic_member(int a) { return a; }
};


int main()
{
	//common function
	std::function<void(int)> func_display_num = print_num;
	func_display_num(9);

	std::function<double(int, char, double)> func_display = f;
	std::cout << func_display(10, 'a', 1.23) << std::endl;


	//lambda expression
	std::function<void(const char*)> lbd_dsp_str = [](const char* s) {std::cout << s << std::endl; };
	lbd_dsp_str("Scala");

	//bind expression
	auto func_num_bind = std::bind(&f, std::placeholders::_1, 'c', 2.4);
	std::cout << func_num_bind(24) << std::endl;

	//function object
	std::function<void(std::string&&)> func_obj_print = PrintString();
	func_obj_print("c++ 17 Nice!");

	const Dog dog(2048);
	std::function<void(const Dog&, int)> func_mem_display_num = &Dog::print_add;
	func_mem_display_num(dog, 24);


	std::function<int(int)> fun_class_mem = TestClass::satic_member;
	std::cout << fun_class_mem(20) << std::endl;

	//std::function<int(int)> fun_class_mem = TestClass::class_member;
	TestClass test_obj;
	fun_class_mem = std::bind(&TestClass::class_member, test_obj, std::placeholders::_1);
	std::cout << fun_class_mem(22) << std::endl;
	system("pause");
	return 0;
}
