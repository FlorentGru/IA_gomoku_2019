#ifndef _LAUNCHER_HPP_
#define _LAUNCHER_HPP_

#include "Protocol.hpp"
#include "brain/Brain.hpp"

class Launcher
{
public:
    Launcher() {}

    int launch();
private:
	int brainLaunch(const std::string& command, Command commandType);
    int launchBoard();

	Protocol protocol;
	Brain brain;
};

#endif // !_LAUNCHER_HPP_