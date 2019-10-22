#include "Brain.hpp"

Brain::Brain()
{
	this->us = WHITE;
	this->them = BLACK;
}

const std::string& Brain::start(int size)
{
	board.start(size);

	answer = "OK";
	return (answer);
}

const std::string& Brain::begin()
{
	int x = 10;
	int y = 10;

	return (createAnswer(x, y));
}

const std::string& Brain::turn(int x, int y)
{
	int x2 = x;
	int y2 = y;

	while (x2 == x && y2 == y) {
		x2 = rand() % BOARD_SIZE;
		y2 = rand() % BOARD_SIZE;
	}
	x = x2;
	y = y2;
	return (createAnswer(x, y));
}

const std::string& Brain::createAnswer(int x, int y)
{
	answer = std::to_string(x) + ',' + std::to_string(y);

	return (answer);
}
