#ifndef _BOARD_HPP_
#define _BOARD_HPP_

#include <array>
#include <vector>

#define BOARD_SIZE 20

using namespace std;

struct Coord {
	int x;
	int y;

	Coord();
	Coord(int x, int y);
	bool operator==(const Coord coord) const;
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
	bool isNod(int x, int y);
	void set(int x, int y, int value);

	void addAxisXNods(int x, int y, vector<Coord>& nods);
	void addAxisYNods(int x, int y, vector<Coord>& nods);
	void addAxisRightDiagNods(int x, int y, vector<Coord>& nods);
	void addAxisLeftDiagNods(int x, int y, vector<Coord>& nods);
	void appendNodLists(vector<Coord>& nods, const vector<Coord>& otherNods);

private:
	void init();

	array<array<int, BOARD_SIZE>, BOARD_SIZE> board;
};

#endif // !_BOARD_HPP_