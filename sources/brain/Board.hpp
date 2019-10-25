#include <array>
#define BOARD_SIZE 20

using namespace std;

struct Coord {
	int x;
	int y;
};

enum PIECE
{
	INIT = 0,
	BLACK = -1,
	WHITE = -2
};

class Board
{
public:
	int start(int size);
	const array<array<int, BOARD_SIZE>, BOARD_SIZE>& add(int x, int y, PIECE piece);
	const array<array<int, BOARD_SIZE>, BOARD_SIZE>& get();
	const int at(int x, int y);

private:
	void init();
	void checkAxisX(int x, int y);
	void checkAxisY(int x, int y);
	void checkAxisRightDiag(int x, int y);
	void checkAxisLeftDiag(int x, int y);


	array<array<int, BOARD_SIZE>, BOARD_SIZE> board;
};