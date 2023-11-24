#include<iostream>
#include<algorithm>

/*
* This program was written to show the reader how to specialize a class template.
* The program was designed in such a way that when it takes string arguments, it
* uses the speciailized template. Any other data types are dealt with using the generic
* class.
*/

template <class T>
class MyClass {
	T val1{};
	T val2{};
	T val3{};

public:
	MyClass(T val1, T val2) {
		this->val1 = val1;
		this->val2 = val2;
		val3 = val1 + val2;
	}

	void showVa() {
		std::cout << "The value of val3 is: " << val3 << std::endl;
	}
};

template <>
class MyClass <std::string> {
	std::string val1{};
	std::string val2{};
	std::string val3{};

public:
	MyClass(std::string val1, std::string val2) {
		this->val1 = val1;
		this->val2 = val2;
		val3 = val1 + val2;

		std::transform(val3.begin(), val3.end(), val3.begin(), [](unsigned char c) {
			return std::tolower(c);  });

		val3 += "@luxoft.com";
	}

	void showVa() {
		std::cout << "The value of val3 is: " << val3 << std::endl;
	}
};

int main() {
	MyClass<int>obj1(4, 5);
	MyClass<double>obj2(1.2, 4.5);
	MyClass<std::string>obj3("ABEL", "ASHENAFI");

	obj1.showVa();
	obj2.showVa();
	obj3.showVa();

	return 0;
}