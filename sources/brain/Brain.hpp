#ifndef _BRAIN_HPP_
#define _BRAIN_HPP_

#include "Board.hpp"
#include "Heuristic.hpp"
#include <string>
#include <vector>

class Brain {
public:
	Brain();

	const std::string& start(int size);
	const std::string& begin();
	const std::string& turn(int x, int y);
	int board(int x, int y, int piece);
    const std::string& boardPlay();
	void end();

private:

private:
	const std::string& play(int x, int y);

    void addNodesToEvaluate(int x, int y, vector<Coord> &nodes);
	void getNodesToEvaluate(int x, int y, vector<Coord> &nodes);

	void evaluateNodes(const vector<Coord>& nodes);
	void evaluateNode(int x, int y);
	Case evaluateAxis(const Axis &axis);

	int combineEvents(Case axisX, Case axisY, Case axisRightDiag, Case axisLeftDiag);
	int winCondition(Case axisX, Case axisY, Case axisRightDiag, Case axisLeftDiag);

	Case checkAxisX(int x, int y);
	Case checkAxisY(int x, int y);
	Case checkAxisRightDiag(int x, int y);
	Case checkAxisLeftDiag(int x, int y);

	const std::string& createAnswer(int x, int y);

	Coord lastMove;
	vector<Coord> boardNodes;

	Heuristic heuristic;
	Board goban;
	PIECE us;
	PIECE them;

	std::string answer;
};

#endif