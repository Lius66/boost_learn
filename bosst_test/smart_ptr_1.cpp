#include<iostream>
#include<string>
#include<memory>

using std::cout;
using std::endl;
using std::shared_ptr;
using std::string;
int main() {
	int *p = new int(10);
	shared_ptr<int> a(p);
	if (a.get() == p)
		cout << "a and p point to the same location" << endl;
	cout << *a.get() << endl;
	cout << *a << endl;
	cout << *p << endl;

	shared_ptr<string> p1 = std::make_shared<string>(10, '9');
	a.reset(new int);
	*a = 20;
	if (a.get() == p)
		cout << "a and p point to the same location" << endl;
	cout << *a.get() << endl;
	cout << *a << endl;
	cout << *p << endl;

	system("pause");
	return 0;
}