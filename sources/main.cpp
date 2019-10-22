#include "Protocol.hpp"
#include "Brain.hpp"

int main(int ac, const char* av[])
{
	Protocol protocol;
	Brain brian;

	while (true) {
		const std::string& command = protocol.getNextCommand();
		Command commandType = protocol.whichCommand(command);


	}
	return (0);
}