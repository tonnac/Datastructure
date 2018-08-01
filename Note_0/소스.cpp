#include <iostream>
#include <functional>

void A(int a, int b)
{
	std::cout << a + b << std::endl;
}

int sum(int num)
{
	if (num <= 1)
		return num;
	sum(num / 2);
}

class CTest
{
public:
	int operator()(int a, int b) const
	{
		std::cout << a + b << std::endl;
		return 0;
	}
	static void printNum(int i)
	{
		std::cout << num + i << std::endl;
	}

	static int num;
};

int CTest::num = 100;

int main()
{
	int a;
	sum(1024);

	return 0;
}