#include <array>
#define BOARD_SIZE 20

using namespace std;

enum PIECE
{
	NONE,
	BLACK,
	WHITE,
};

class Board 
{
public:
	int start(int size);
	const array<array<PIECE, BOARD_SIZE>, BOARD_SIZE>& add(int x, int y, PIECE piece);
	const array<array<PIECE, BOARD_SIZE>, BOARD_SIZE>& get();
	const PIECE at(int x, int y);
private:
	void init();

	array<array<PIECE, BOARD_SIZE>, BOARD_SIZE> board;
};