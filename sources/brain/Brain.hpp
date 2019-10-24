#ifndef _BRAIN_HPP_
#define _BRAIN_HPP_

#include "Board.hpp"
#include <string>
#include <vector>

class Brain {
public:
	Brain();

	const std::string& start(int size);
	const std::string& begin();
	const std::string& turn(int x, int y);
	const std::string& board(int x, int y, int piece);
	void end();

private:
	const std::string& play();

	void getNodsToEvaluate(int x, int y, vector<Coord> &nods);

	void evaluateNode(int x, int y);
	void checkAxisX(int x, int y);
	void checkAxisY(int x, int y);
	void checkAxisRightDiag(int x, int y);
	void checkAxisLeftDiag(int x, int y);

	const std::string& createAnswer(int x, int y);

	Coord lastPlay;

	Board goban;
	PIECE us;
	PIECE them;

	std::string answer;
};

#endif