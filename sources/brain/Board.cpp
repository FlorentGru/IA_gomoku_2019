#include "Board.hpp"
#include <algorithm>

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

int Board::at(int x, int y)
{
	return board[x][y];
}

bool Board::isNode(int x, int y)
{
	if (board[x][y] >= 0)
		return true;
	return false;
}

void Board::set(int x, int y, int value)
{
	board[x][y] = value;
}

Coord Board::getHighestValue()
{
	int value = -1;
	int x = 0;
	Coord res;

	for (const auto& column : board) {
		int y = 0;
		for (const auto& node : column) {
			if (node > value) {
				value = node;
				res.x = x;
				res.y = y;
			}
			y++;
		}
		x++;
	}
	return res;
}

void Board::getNodesCoord(int x, int y, vector<Coord>& nodes)
{
	addAxisXNodes(x, y, nodes);
	addAxisYNodes(x, y, nodes);
	addAxisRightDiagNodes(x, y, nodes);
	addAxisLeftDiagNodes(x, y, nodes);
}

void Board::addAxisXNodes(int x, int y, vector<Coord>& nodes)
{
	for (int i = 1; i <= 5 && x + i < 20; i++) {
		if (isNode(x + i, y))
			nodes.emplace_back(Coord(x + i, y));
	}
	for (int i = 1; i <= 5 && x - i >= 0; i++) {
		if (isNode(x - i, y))
			nodes.emplace_back(Coord(x - i, y));
	}
}

void Board::addAxisYNodes(int x, int y, vector<Coord>& nodes)
{
	for (int i = 1; i <= 5 && y + i < 20; i++) {
		if (isNode(x, y + i))
			nodes.emplace_back(Coord(x, y + i));
	}
	for (int i = 1; i <= 5 && y - i >= 0; i++) {
		if (isNode(x, y - i))
			nodes.emplace_back(Coord(x, y - i));
	}
}

void Board::addAxisRightDiagNodes(int x, int y, vector<Coord> & nodes)
{
    for (int i = 1; i <= 5 && y + i < 20 && x - i >= 0; i++) {
        if (isNode(x - i, y + i))
            nodes.emplace_back(Coord(x - i, y + i));
    }
    for (int i = 1; i <= 5 && x + i < 20 && y - i >= 0; i++) {
        if (isNode(x + i, y - i))
            nodes.emplace_back(Coord(x + i, y - i));
    }
}

void Board::addAxisLeftDiagNodes(int x, int y, vector<Coord>& nodes)
{
	for (int i = 1; i <= 5 && y + i < 20 && x + i < 20; i++) {
		if (isNode(x + i, y + i))
			nodes.emplace_back(Coord(x + i, y + i));
	}
	for (int i = 1; i <= 5 && x - i >= 0 && y - i >= 0; i++) {
		if (isNode(x - i, y - i))
			nodes.emplace_back(Coord(x - i, y - i));
	}
}

void Board::appendNodeLists(vector<Coord>& nodes, const vector<Coord>& otherNodes)
{
	for (const auto& node : otherNodes) {
		if (find(nodes.cbegin(), nodes.cend(), node) == nodes.end())
			nodes.push_back(node);
	}
}

void Board::getAxisX(int x, int y, Axis &nodes)
{
    for (int i = 1; i <= 5 && x + i < 20; i++) {
        nodes.up.emplace_back(Coord(x + i, y));
    }
    for (int i = 1; i <= 5 && x - i >= 0; i++) {
        nodes.down.emplace_back(Coord(x - i, y));
    }
}

void Board::getAxisY(int x, int y, Axis &nodes)
{
    for (int i = 1; i <= 5 && y + i < 20; i++) {
        nodes.up.emplace_back(Coord(x, y + i));
    }
    for (int i = 1; i <= 5 && y - i >= 0; i++) {
        nodes.down.emplace_back(Coord(x, y - i));
    }
}

void Board::getAxisRightDiag(int x, int y, Axis &nodes)
{
    for (int i = 1; i <= 5 && y + i < 20 && x - i >= 0; i++) {
        nodes.up.emplace_back(Coord(x - i, y + i));
    }
    for (int i = 1; i <= 5 && x + i < 20 && y - i >= 0; i++) {
        nodes.down.emplace_back(Coord(x + i, y - i));
    }
}

void Board::getAxisLeftDiag(int x, int y, Axis &nodes)
{
    for (int i = 1; i <= 5 && y + i < 20 && x + i < 20; i++) {
        nodes.up.emplace_back(Coord(x + i, y + i));
    }
    for (int i = 1; i <= 5 && x - i >= 0 && y - i >= 0; i++) {
        nodes.down.emplace_back(Coord(x - i, y - i));
    }
}

void Board::init()
{
	for (auto& column : board) {
		column.fill(INIT);
	}
}

void Board::checkAxisX(int x, int y)
{
	for (int i = 0; i > 4 && x < 20; i++) {
		at(x, y);
		x++;
	}
	x = x - 4;
	for (int i = 0; i > 4 && x < 20; i++) {
		at(x, y);
		x--;
	}
}

void Board::checkAxisY(int x, int y)
{
	for (int i = 0; i > 4 && y < 20; i++) {
		at(x, y);
		y++;
	}
	y = y - 4;
	for (int i = 0; i > 4 && y < 20; i++) {
		at(x, y);
		y--;
	}
}

void Board::checkAxisRightDiag(int x, int y)
{
	for (int i = 0; i < 4 && y < 20 && x < 20; i++) {
		at(x, y);
		x++;
		y++;
	}
	x = x - 4;
	y = y - 4;
	for (int i = 0; i < 4 && x < 20 && y < 20; i++) {
		at(x, y);
		x--;
		y--;
	}
}

void Board::checkAxisLeftDiag(int x, int y)
{
	for (int i = 0; i < 4 && x < 20 && y < 20; i++) {
		at(x, y);
		x--;
		y++;
	}
	x = x - 4;
	y = y - 4;
	for (int i = 0; i < 4 && x < 20 && y < 20; i++) {
		at(x, y);
		x++;
		y--;
	}
}
Coord::Coord()
{
	this->x = 0;
	this->y = 0;
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
