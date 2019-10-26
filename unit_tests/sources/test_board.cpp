/*
** EPITECH PROJECT, 2019
** AIA_gomoku_2019
** File description:
** test_board.cpp
*/

#include <criterion/criterion.h>
#include "Board.hpp"

Test(At, expect_good_return)
{
    Board call_board;
    int x = 10;
    int y = 10;

    // cr_expect_eq(call_board.at(x, y), "10, 10");
}

Test(start_board, expect_good_return)
{
    Board board;

    cr_expect_eq(board.start(20), 0);
}

Test(start_board, check_case_error)
{
    Board board;

    cr_expect_eq(board.start(2), 84);
}

Test(isNode, expext_return_true)
{
    Board board;

    board.get();

    cr_expect_eq(board.isNode(10, 10), true);
}

Test(isNode, expext_return_false)
{
    Board board;

    cr_expect_eq(board.isNode(0, 0), false);
}

