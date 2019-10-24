#include <iostream>
#include <sstream>
#include "Protocol.hpp"

std::string Protocol::getNextCommand()
{
    std::string command;

    std::getline(std::cin, command);
	return (command);
}

Command Protocol::whichCommand(const std::string &command)
{
    const std::vector<std::string> &words = split(command, ' ');

    if (words.front() == "START") {
        return (START);
    } else if (words.front() == "BEGIN") {
        return (BEGIN);
    } else if (words.front() == "TURN") {
        return (TURN);
	} else if (words.front() == "BOARD") {
		return (BOARD);
	} else if (words.front() == "INFO") {
		return (INFO);
    } else if (words.front() == "END")
        return (END);
    return (UNKNOWN);
}

int Protocol::getStartArg(const std::string& command)
{
	std::vector<std::string> arg = split(command, ' ');
	int size;

	if (arg.size() != 2) {
		return (20);
	}
	size = std::stoi(arg[1]);
	return (size);
}

const std::pair<int, int>& Protocol::getTurnArg(const std::string& command)
{
	std::vector<std::string> arg = split(command, ' ');
	std::pair<int, int> turnArg = { -1, -1 };

	if (arg.size() != 2) {
		return (turnArg);
	}

	arg = split(arg[1], ',');
	if (arg.size() != 2) {
		return (turnArg);
	}

	turnArg.first = std::stoi(arg[0]);
	turnArg.second = std::stoi(arg[1]);
	return (turnArg);
}

const BoardArg Protocol::getBoardArg(const std::string& command)
{
	std::vector<std::string> arg = split(command, ',');
	BoardArg boardArg = { -1, -1, -1 };

	if (arg.size() != 3) {
		return (boardArg);
	}
	boardArg.x = std::stoi(arg[0]);
	boardArg.y = std::stoi(arg[1]);
	boardArg.player = std::stoi(arg[2]);
	return (boardArg);
}

int Protocol::unknown()
{
	std::cout << "UNKNOWN command is unknown" << std::endl;
	return 0;
}

int Protocol::answer(const std::string& rep)
{
	std::cout << rep << std::endl;
	return 0;
}

const std::vector<std::string> Protocol::split(const std::string &string, char delimiter)
{
    std::vector<std::string> words;
    std::stringstream strStream(string);
    std::string buffer;

    while (std::getline(strStream, buffer, delimiter)) {
        words.push_back(buffer);
    }
    return (words);
}