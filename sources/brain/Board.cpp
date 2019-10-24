#include "Board.hpp"

int Board::start(int size)
{
	if (size != BOARD_SIZE) {
		return (84);
	}

	init();
	return (0);
}

const array<array<int, BOARD_SIZE>, BOARD_SIZE>& Board::add(int x, int y, PIECE piece)
{
	board[x][y] = piece;

	return (board);
}

const array<array<int, BOARD_SIZE>, BOARD_SIZE>& Board::get()
{
	return (board);
}

const int Board::at(int x, int y)
{
	return board[x][y];
}

bool Board::isNod(int x, int y)
{
	if (board[x][y] >= 0)
		return true;
	return false;
}

void Board::set(int x, int y, int value)
{
	board[x][y] = value;
}

void Board::addAxisXNods(int x, int y, vector<Coord>& nods)
{
	for (int i = 1; i <= 5 && x + i < 20; i++) {
		if (isNod(x + i, y))
			nods.push_back(Coord(x + i, y));
	}
	for (int i = 1; i <= 5 && x - i >= 0; i++) {
		if (isNod(x - i, y))
			nods.emplace_back(Coord(x - i, y));
	}
}

void Board::addAxisYNods(int x, int y, vector<Coord>& nods)
{
	for (int i = 1; i <= 5 && y + i < 20; i++) {
		if (isNod(x, y + i))
			nods.push_back(Coord(x, y + i));
	}
	for (int i = 1; i <= 5 && y - i >= 0; i++) {
		if (isNod(x, y - i))
			nods.emplace_back(Coord(x, y - i));
	}
}

void Board::addAxisRightDiagNods(int x, int y, vector<Coord> & nods)
{
	for (int i = 1; i <= 5 && y + i < 20 && x - i >= 0; i++) {
		if (isNod(x - i, y + i))
			nods.push_back(Coord(x - i, y + i));
	}
	for (int i = 1; i <= 5 && x + i < 20 && y - i >= 0; i++) {
		if (isNod(x + i, y - i))
			nods.emplace_back(Coord(x + i, y - i));
	}
}

void Board::addAxisLeftDiagNods(int x, int y, vector<Coord>& nods)
{
	for (int i = 1; i <= 5 && y + i < 20 && x + i < 20; i++) {
		if (isNod(x + i, y + i))
			nods.push_back(Coord(x + i, y + i));
	}
	for (int i = 1; i <= 5 && x - i >= 0 && y - i >= 0; i++) {
		if (isNod(x - i, y - i))
			nods.emplace_back(Coord(x - i, y - i));
	}
}

void Board::appendNodLists(vector<Coord>& nods, const vector<Coord>& otherNods)
{
	for (const auto& value : otherNods) {
		if (find(nods.cbegin(), nods.cend(), value) == nods.end())
			nods.push_back(value);
	}
}

void Board::init()
{
	for (auto& column : board) {
		column.fill(INIT);
	}
}

Coord::Coord()
{
	int x = 0;
	int y = 0;
}

Coord::Coord(int x, int y)
{
	this->x = x;
	this->y = y;
}

bool Coord::operator==(const Coord coord) const
{
	if (coord.x == this->x && coord.y == this->y)
		return true;
	return false;
}
