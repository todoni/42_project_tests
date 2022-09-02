#include <iostream>

int	main(int argc, char **argv)
{
	(void)argv;
	int	a;
	a = argc;
	static const int b = a;
	constexpr int c = a;
	std::cout << b << std::endl;
	return (0);
}
