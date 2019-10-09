#include <iostream>
#include "Protocol.hpp"

std::string Protocol::getNextCommand()
{
    std::string command;

    std::getline(std::cin, command, '\r');
    return (command);
}

Command Protocol::whichCommand(const std::string &command)
{
    const std::vector<std::string> &words = split(command, ' ');

    if (words.front = "START") {
        return (START);
    } else if (words.front = "BEGIN") {
        return (BEGIN);
    } else if (words.front = "TURN") {
        return (TURN);
    } else if (words.front = "BOARD") {
        return (BOARD);
    } else if (words.front = "END")
        return (END);
    return (UNKNOWN);
}

const std::vector<std::string> &Protocol::split(const std::string &string, char delimiter)
{
    std::vector<std::string> words;
    std::istream strStream(string.c_str);
    std::string buffer;

    while (std::getline(strStream, buffer, delimiter)) {
        words.push_back(buffer);
    }
    return (words);
}