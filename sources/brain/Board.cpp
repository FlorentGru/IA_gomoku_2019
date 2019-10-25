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