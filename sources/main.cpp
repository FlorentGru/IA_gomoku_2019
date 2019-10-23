#include "Launcher.hpp"
#include <iostream>

int main(int ac, const char* av[])
{
	Launcher laucher;
	int rep = 0;

	while (rep == 0) {
		rep = laucher.launch();
		if (rep == 84) {
			std::cerr << "Error: error occured" << std::endl;
			return (84);
		}
	}
	return (0);
}