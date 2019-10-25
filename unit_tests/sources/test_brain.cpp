/*
** EPITECH PROJECT, 2019
** AIA_gomoku_2019
** File description:
** test_brain.cpp
*/

#include <criterion/criterion.h>
#include "Brain.hpp"

Test(start_command, expect_print_good_type)
{
    Brain brain;
    std::string answer = brain.start(20);

    cr_expect_str_eq(answer.c_str(), "OK");
}

Test(start_command, expect_print_wrong_type)
{
    Brain brain;
    std::string answer = brain.start(3);

    cr_expect_str_eq(answer.c_str(), "ERROR unsupported size");
}

Test(start_command, expect_print_wrong_type_for_zero)
{
    Brain brain;
    std::string answer = brain.start(0);

    cr_expect_str_eq(answer.c_str(), "ERROR unsupported size");
}

Test(turn_command, expect_good_return)
{
    Brain brain;
    
    cr_expect_eq(brain.play(), brain.play());
}