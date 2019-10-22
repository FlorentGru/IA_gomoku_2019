#include "Board.hpp"
#include <string>

class Brain {
public:
	Brain();

	const std::string& start(int size);
	const std::string& begin();
	const std::string& turn(int x, int y);

private:
	const std::string& createAnswer(int x, int y);

	Board board;
	PIECE us;
	PIECE them;

	std::string answer;
};