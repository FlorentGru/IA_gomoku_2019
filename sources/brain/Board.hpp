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

struct Axis {
    vector<Coord> up;
    vector<Coord> down;
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

	const array<array<int, BOARD_SIZE>, BOARD_SIZE>& add(int x, int y, int piece);
	const array<array<int, BOARD_SIZE>, BOARD_SIZE>& get();

	int at(int x, int y);
	bool isNode(int x, int y);
	void set(int x, int y, int value);
	Coord getHighestValue();

	void getNodesCoord(int x, int y, vector<Coord>& nodes);
	void addAxisXNodes(int x, int y, vector<Coord>& nodes);
	void addAxisYNodes(int x, int y, vector<Coord>& nodes);
	void addAxisRightDiagNodes(int x, int y, vector<Coord>& nodes);
	void addAxisLeftDiagNodes(int x, int y, vector<Coord>& nodes);

	void appendNodeLists(vector<Coord>& nods, const vector<Coord>& otherNodes);

    void getAxisX(int x, int y, Axis &nodes);
    void getAxisY(int x, int y, Axis &nodes);
    void getAxisRightDiag(int x, int y, Axis &nodes);
    void getAxisLeftDiag(int x, int y, Axis &nodes);
private:
	void init();
	void checkAxisX(int x, int y);
	void checkAxisY(int x, int y);
	void checkAxisRightDiag(int x, int y);
	void checkAxisLeftDiag(int x, int y);


	array<array<int, BOARD_SIZE>, BOARD_SIZE> board;
};

#endif // !_BOARD_HPP_