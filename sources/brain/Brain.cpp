#include "Brain.hpp"
#include <algorithm>

Brain::Brain()
{
	this->us = WHITE;
	this->them = BLACK;
}

const std::string& Brain::start(int size)
{
	answer = "OK";

	if (goban.start(size) == 84)
		answer = "ERROR unsupported size";

	return (answer);
}

const std::string& Brain::begin()
{
	int x = 10;
	int y = 10;

	this->us = BLACK;
	this->them = WHITE;

	return (createAnswer(x, y));
}

const std::string& Brain::turn(int x, int y)
{
	goban.add(x, y, them);

	return (play(x, y));
}

const std::string& Brain::board(int x, int y, int piece)
{
	return (play(x, y));
}

void Brain::end()
{
}

const std::string& Brain::play(int x, int y)
{
	vector<Coord> nods;

	getNodesToEvaluate(x, y, nods);
	evaluateNodes(nods);

	Coord result = goban.getHighestValue();

	return (createAnswer(result.x, result.y));
}

void Brain::getNodesToEvaluate(int x, int y, vector<Coord> &nodes)
{
	nodes.clear();
	goban.getNodesCoord(x, y, nodes);

	vector<Coord> otherNodes;
	goban.getNodesCoord(lastMove.x, lastMove.y, otherNodes);

	goban.appendNodeLists(nodes, otherNodes);
}

void Brain::evaluateNodes(const vector<Coord>& nodes)
{
	for (const auto& node : nodes) {
		// evaluateNode(node.x, node.y);
	}
}

const std::string& Brain::createAnswer(int x, int y)
{
	lastMove.x = x;
	lastMove.y = y;

	goban.add(x, y, us);

	answer = std::to_string(x) + ',' + std::to_string(y);
	return (answer);
}