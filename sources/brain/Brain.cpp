#include "Brain.hpp"
#include <algorithm>

Brain::Brain()
{
	this->us = WHITE;
	this->them = BLACK;
}

const std::string& Brain::start(int size)
{
	if (goban.start(size) == 84) {
		answer = "ERROR unsupported size";
		return (answer);
	}

	answer = "OK";
	return (answer);
}

const std::string& Brain::begin()
{
	int x = 10;
	int y = 10;

	goban.add(x, y, us);
	return (createAnswer(x, y));
}

const std::string& Brain::turn(int x, int y)
{
	goban.add(x, y, them);
	return (play());
}

const std::string& Brain::board(int x, int y, int piece)
{

	play();
	return (answer);
}

void Brain::end()
{
	goban.start(BOARD_SIZE);
}

const std::string& Brain::play()
{
	int x = 0;
	int y = 0;

	while (goban.at(x, y) != INIT) {
		x = rand() % BOARD_SIZE;
		y = rand() % BOARD_SIZE;
	}

	lastPlay.x = x;
	lastPlay.y = y;
	goban.add(x, y, us);
	return (createAnswer(x, y));
}

void Brain::getNodsToEvaluate(int x, int y, vector<Coord> &nods)
{
	nods.clear();

	goban.addAxisXNods(x, y, nods);
	goban.addAxisXNods(x, y, nods);
	goban.addAxisRightDiagNods(x, y, nods);
	goban.addAxisLeftDiagNods(x, y, nods);

	vector<Coord> otherNods;

	goban.addAxisXNods(x, y, otherNods);
	goban.addAxisXNods(x, y, otherNods);
	goban.addAxisRightDiagNods(x, y, otherNods);
	goban.addAxisLeftDiagNods(x, y, otherNods);

	goban.appendNodLists(nods, otherNods);
}

const std::string& Brain::createAnswer(int x, int y)
{
	answer = std::to_string(x) + ',' + std::to_string(y);

	return (answer);
}
