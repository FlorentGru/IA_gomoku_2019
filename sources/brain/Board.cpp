#include "Board.hpp"

void Board::start(int size)
{
}

const std::vector<PIECE>& Board::add(int x, int y, PIECE piece)
{
	board[x][y] = piece;

	return (board);
}

const std::vector<PIECE>& Board::get()
{
	return (board);
}
