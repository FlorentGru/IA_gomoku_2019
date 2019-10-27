#include "Brain.hpp"
#include <algorithm>
#include <iostream>

Brain::Brain() : heuristic(goban.get()), goban()
{
	this->us = WHITE;
	this->them = BLACK;

    heuristic.setPlayers(us, them);
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
    heuristic.setPlayers(us, them);

    return (createAnswer(x, y));
}

const std::string& Brain::turn(int x, int y)
{
	goban.add(x, y, them);

	return (play(x, y));
}

int Brain::board(int x, int y, int piece)
{
    PIECE it;

    if (piece == 1) {
        it = this->us;
    } else {
        it = this->them;
    }

    goban.add(x, y, it);
    boardNodes.emplace_back(Coord(x, y));

	return (0);
}

const std::string& Brain::boardPlay()
{
    vector<Coord> nodes;

    for (const auto &coord : boardNodes) {
        addNodesToEvaluate(coord.x, coord.y, nodes);
    }
    evaluateNodes(nodes);

    Coord result = goban.getHighestValue();

    return (createAnswer(result.x, result.y));
}

void Brain::addNodesToEvaluate(int x, int y, vector<Coord> &nodes)
{
    vector<Coord> newNodes;
    goban.getNodesCoord(x, y, newNodes);

    goban.appendNodeLists(nodes, newNodes);
}

void Brain::end()
{
}

const std::string& Brain::play(int x, int y)
{
	vector<Coord> nodes;

	getNodesToEvaluate(x, y, nodes);
	evaluateNodes(nodes);

	Coord result = goban.getHighestValue();

	return (createAnswer(result.x, result.y));
}

void Brain::getNodesToEvaluate(int x, int y, vector<Coord> &nodes)
{
	goban.getNodesCoord(x, y, nodes);

	vector<Coord> otherNodes;
	goban.getNodesCoord(lastMove.x, lastMove.y, otherNodes);

	goban.appendNodeLists(nodes, otherNodes);
}

void Brain::evaluateNodes(const vector<Coord>& nodes)
{
	for (const auto& node : nodes) {
		evaluateNode(node.x, node.y);
	}
}

void Brain::evaluateNode(int x, int y)
{
    int value = 0;

    const Case axisX = checkAxisX(x, y);
    const Case axisY = checkAxisY(x, y);
    const Case axisRightDiag = checkAxisRightDiag(x, y);
    const Case axisLeftDiag = checkAxisLeftDiag(x, y);

    value = combineEvents(axisX, axisY, axisRightDiag, axisLeftDiag);

    goban.set(x, y, value);
}

int Brain::combineEvents(Case axisX, Case axisY, Case axisRightDiag, Case axisLeftDiag)
{
    int value = 0;

    value += winCondition(axisX, axisY, axisRightDiag, axisLeftDiag);

    value += heuristic.getRank(axisX);
    value += heuristic.getRank(axisY);
    value += heuristic.getRank(axisRightDiag);
    value += heuristic.getRank(axisLeftDiag);

    return value;
}

Case Brain::evaluateAxis(const Axis &axis)
{
    Case res = NONE;

    res = heuristic.isFour(axis);
    if (res != NONE) {
        return res;
    }

    res = heuristic.isThree(axis);
    if (res != NONE) {
        return res;
    }

    res = heuristic.isTwo(axis);
    if (res != NONE) {
        return res;
    }

    res = heuristic.isOne(axis);
    return res;
}

Case Brain::checkAxisX(int x, int y)
{
    Case res;
    Axis axis;

    goban.getAxisX(x, y, axis);

    res = evaluateAxis(axis);
    return (res);
}

Case Brain::checkAxisY(int x, int y)
{
    Case res;
    Axis axis;

    goban.getAxisY(x, y, axis);

    res = evaluateAxis(axis);
    return (res);
}

Case Brain::checkAxisRightDiag(int x, int y)
{
    Case res;
    Axis axis;

    goban.getAxisRightDiag(x, y, axis);

    res = evaluateAxis(axis);
    return (res);
}

Case Brain::checkAxisLeftDiag(int x, int y)
{
    Case res;
    Axis axis;

    goban.getAxisLeftDiag(x, y, axis);

    res = evaluateAxis(axis);
    return (res);
}

const std::string& Brain::createAnswer(int x, int y)
{
	lastMove.x = x;
	lastMove.y = y;

	goban.add(x, y, us);

	answer = std::to_string(x) + ',' + std::to_string(y);
	return (answer);
}

int Brain::winCondition(Case axisX, Case axisY, Case axisRightDiag, Case axisLeftDiag)
{
    int count = 0;
    if (axisX == TWO_FRIENDLY)
        count++;
    if (axisY == TWO_FRIENDLY)
        count++;
    if (axisRightDiag == TWO_FRIENDLY)
        count++;
    if (axisLeftDiag == TWO_FRIENDLY)
        count++;
    if (count >= 2)
        return 40;
    return 0;
}
