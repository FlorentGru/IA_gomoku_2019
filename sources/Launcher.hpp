#include "Protocol.hpp"
#include "brain/Brain.hpp"

class Launcher
{
public:
	int launch();
private:
	int brainLaunch(const std::string& command, Command commandType);

	Protocol protocol;
	Brain brain;
};