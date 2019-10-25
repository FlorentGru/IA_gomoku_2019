#include "Board.hpp"
#include <string>

class Brain {
public:
	Brain();

	const std::string& start(int size);
	const std::string& begin();
	const std::string& turn(int x, int y);
	const std::string& board(int x, int y, int piece);
	void end();
	const std::string& play();

private:

	const std::string& createAnswer(int x, int y);

	Board goban;
	PIECE us;
	PIECE them;

	std::string answer;
};