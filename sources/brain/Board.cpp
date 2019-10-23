#include "Board.hpp"

int Board::start(int size)
{
	if (size != BOARD_SIZE) {
		return (84);
	}

	init();
	return (0);
}

const array<array<PIECE, BOARD_SIZE>, BOARD_SIZE>& Board::add(int x, int y, PIECE piece)
{
	board[x][y] = piece;

	return (board);
}

const array<array<PIECE, BOARD_SIZE>, BOARD_SIZE>& Board::get()
{
	return (board);
}

const PIECE Board::at(int x, int y)
{
	return board[x][y];
}

void Board::init()
{
	for (auto& column : board) {
		column.fill(NONE);
	}
}
