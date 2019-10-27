#include "Heuristic.hpp"
#include <iostream>

Heuristic::Heuristic(const array<array<int, BOARD_SIZE>, BOARD_SIZE> &board)
: board(board) {
    mode = DEFENCE;
}

void Heuristic::setPlayers(PIECE us, PIECE them)
{
    this->_us = us;
    this->_them = them;

    if (us == WHITE && mode != DEFENCE)
        setMode(DEFENCE);
    else if (mode != ATTACK)
        setMode(ATTACK);
}

void Heuristic::setMode(bool _mode)
{
    mode = _mode;

    int oneFriendly = ranks[ONE_FRIENDLY];
    int oneFriendlyBlocked = ranks[ONE_FRIENDLY_BLOCKED];
    int twoFriendlyBlocked = ranks[TWO_FRIENDLY_BLOCKED];

    ranks[ONE_FRIENDLY] = ranks[ONE_ENEMY];
    ranks[ONE_FRIENDLY_BLOCKED] = ranks[ONE_ENEMY_BLOCKED];
    ranks[TWO_FRIENDLY_BLOCKED] = ranks[TWO_ENEMY_BLOCKED];

    ranks[ONE_ENEMY] = oneFriendly;
    ranks[ONE_ENEMY_BLOCKED] = oneFriendlyBlocked;
    ranks[TWO_ENEMY_BLOCKED] = twoFriendlyBlocked;
}

int Heuristic::getRank(Case event)
{
	return (ranks.at(event));
}

Case Heuristic::isFour(const Axis &axis)
{
    Case res = NONE;

    res = isFourFriendly(axis);
    if (res != NONE)
        return res;

    res = isFourEnemy(axis);
    if (res != NONE)
        return res;

    return NONE;
}

Case Heuristic::isFourFriendly(const Axis &axis)
{
    Case res = NONE;

    res = fourAlgo(axis.up, axis.down, FRIENDLY);
    if (res != NONE)
        return res;

    res = fourAlgo(axis.down, axis.up, FRIENDLY);
    if (res != NONE)
        return res;
    return NONE;
}

Case Heuristic::isFourEnemy(const Axis &axis)
{
    Case res = NONE;

    res = fourAlgo(axis.up, axis.down, ENEMY);
    if (res != NONE)
        return res;

    res = fourAlgo(axis.down, axis.up, ENEMY);
    if (res != NONE)
        return res;
    return NONE;
}

Case Heuristic::isThree(const Axis &axis)
{
    Case res = NONE;

    res = isThreeFriendly(axis);
    if (res != NONE)
        return res;

    res = isThreeEnemy(axis);
    if (res != NONE)
        return res;

    return NONE;
}

Case Heuristic::isThreeFriendly(const Axis &axis)
{
    Case res = NONE;

    res = threeFriendlyAlgo(axis.up, axis.down);
    if (res != NONE)
        return res;

    res = threeFriendlyAlgo(axis.down, axis.up);
    if (res != NONE)
        return res;
    return NONE;
}

Case Heuristic::isThreeEnemy(const Axis &axis)
{
    Case res = NONE;

    res = threeEnemyAlgo(axis.up, axis.down);
    if (res != NONE)
        return res;

    res = threeEnemyAlgo(axis.down, axis.up);
    if (res != NONE)
        return res;
    return NONE;
}

Case Heuristic::isTwo(const Axis &axis)
{
    Case res = NONE;

    if (axis.up.empty() || axis.down.empty())
        return res;

    res = isTwoFriendly(axis);
    if (res != NONE)
        return res;

    res = isTwoEnemy(axis);
    if (res != NONE)
        return res;

    return NONE;
}

Case Heuristic::isTwoFriendly(const Axis &axis)
{
    Case res = NONE;

    res = twoAlgo(axis.up, axis.down, FRIENDLY);
    if (res != NONE)
        return res;

    res = twoAlgo(axis.down, axis.up, FRIENDLY);
    if (res != NONE)
        return res;
    return NONE;
}

Case Heuristic::isTwoEnemy(const Axis &axis)
{
    Case res = NONE;

    res = twoAlgo(axis.up, axis.down, ENEMY);
    if (res != NONE)
        return res;

    res = twoAlgo(axis.down, axis.up, ENEMY);
    if (res != NONE)
        return res;
    return NONE;
}


Case Heuristic::isOne(const Axis &axis)
{
    Case res = NONE;

    if (axis.up.empty() || axis.down.empty())
        return res;

    if (mode == ATTACK) {
        res = isOneFriendly(axis);
        if (res != NONE)
            return res;

        res = isOneEnemy(axis);
        if (res != NONE)
            return res;
    } else {
        res = isOneEnemy(axis);
        if (res != NONE)
            return res;

        res = isOneFriendly(axis);
        if (res != NONE)
            return res;
    }
    return NONE;
}

Case Heuristic::isOneFriendly(const Axis &axis)
{
    Case res = NONE;

    res = oneAlgo(axis.up, axis.down, FRIENDLY);
    if (res != NONE)
        return res;

    res = oneAlgo(axis.down, axis.up, FRIENDLY);
    if (res != NONE)
        return res;
    return NONE;
}

Case Heuristic::isOneEnemy(const Axis &axis)
{
    Case res = NONE;

    res = oneAlgo(axis.up, axis.down, ENEMY);
    if (res != NONE)
        return res;

    res = oneAlgo(axis.down, axis.up, ENEMY);
    if (res != NONE)
        return res;
    return NONE;
}

Case Heuristic::fourAlgo(const vector<Coord> &up, const vector<Coord> &down, bool friendly)
{
    Case success = FOUR_FRIENDLY;
    PIECE us = _us;

    if (!friendly) {
        success = FOUR_ENEMY;
        us = _them;
    }

    if (up.size() >= 4 &&
        at(up[0]) == us && at(up[1]) == us && at(up[2]) == us && at(up[3]) == us) {
        return success;
    }

    if (up.size() > 2 && !down.empty() &&
        at(up[0]) == us && at(up[1]) == us && at(up[2]) == us && at(down[0]) == us) {
        return success;
    }

    if (up.size() > 1 && down.size() > 1 &&
        at(up[0]) == us && at(up[1]) == us && at(down[0]) == us && at(down[1]) == us) {
        return success;
    }

    return NONE;
}

Case Heuristic::threeFriendlyAlgo(const vector<Coord> &up, const vector<Coord> &down)
{
    Case success = THREE_FRIENDLY;
    Case blocked = THREE_FRIENDLY_BLOCKED;
    PIECE us = _us;
    PIECE them = _them;

    if (up.size() >= 4) {
        if (at(up[0]) == us && at(up[1]) != them && at(up[2]) == us && at(up[3]) == us) {
            return blocked;
        }

        if (at(up[0]) == us && at(up[2]) != them && at(up[1]) == us && at(up[3]) == us) {
            return blocked;
        }

        if (at(up[0]) != them && at(up[1]) == us && at(up[2]) == us && at(up[3]) == us) {
            return blocked;
        }
    }

    if (up.size() >= 3 &&
        at(up[0]) == us && at(up[1]) == us && at(up[2]) == us) {
        if (up.size() >= 4 && at(up[3]) != them && !down.empty() && at(down[0]) != them)
            return success;
        if ((up.size() < 4 || at(up[3]) == them) && (down.empty() || at(down[0]) == them))
            return NONE;
        if (up.size() < 4 || at(up[3]) == them || down.empty() || at(down[0]) == them)
            return blocked;
    }

    if (up.size() >= 2 && !down.empty() &&
        at(up[0]) == us && at(up[1]) == us && at(down[0]) == us) {
        if (up.size() >= 3 && at(up[2]) != them && down.size() > 1 && at(down[1]) != them)
            return success;
        if ((up.size() < 3 || at(up[2]) == them) && (down.size() <= 1 || at(down[1]) == them))
            return NONE;
        if (up.size() < 3 || at(up[2]) == them || down.size() <= 1 || at(down[1]) == them)
            return blocked;
    }

    if (up.size() >= 3 && !down.empty() &&
        at(up[0]) == us && at(up[1]) != them && at(up[2]) == us && at(down[0]) == us) {
        return blocked;
    }

    return NONE;
}

Case Heuristic::threeEnemyAlgo(const vector<Coord> &up, const vector<Coord> &down)
{
    Case success = THREE_ENEMY;
    Case blocked = THREE_ENEMY_BLOCKED;
    PIECE us = _them;
    PIECE them = _us;

    if (up.size() >= 4) {
        if (at(up[0]) == us && at(up[1]) != them && at(up[2]) == us && at(up[3]) == us) {
            if (up.size() >= 5 && at(up[4]) != them)
                return success;
            return blocked;
        }

        if (at(up[0]) == us && at(up[2]) != them && at(up[1]) == us && at(up[3]) == us) {
            if (up.size() >= 5 && at(up[4]) != them)
                return success;
            return blocked;
        }
    }

    if (up.size() >= 3 &&
        at(up[0]) == us && at(up[1]) == us && at(up[2]) == us) {
        if (up.size() >= 4 && at(up[3]) != them) {
            if ((!down.empty() && at(down[0]) != them) || (up.size() == 5 && at(up[4]) != them)) {
                return success;
            }
            return blocked;
        }
        if ((up.size() < 4 || at(up[3]) == them) && (down.empty() || at(down[0]) == them))
            return NONE;
        if (up.size() < 4 || at(up[3]) == them || down.empty() || at(down[0]) == them)
            return blocked;
    }

    if (up.size() >= 2 && !down.empty() &&
        at(up[0]) == us && at(up[1]) == us && at(down[0]) == us) {
        if (up.size() >= 3 && at(up[2]) != them && down.size() > 1 && at(down[1]) != them)
            return success;
        if ((up.size() < 3 || at(up[2]) == them) && (down.size() <= 1 || at(down[1]) == them))
            return NONE;
        if (up.size() < 3 || at(up[2]) == them || down.size() <= 1 || at(down[1]) == them)
            return blocked;
    }

    if (up.size() >= 3 && !down.empty() &&
        at(up[0]) == us && at(up[1]) != them && at(up[2]) == us && at(down[0]) == us) {
        return blocked;
    }

    return NONE;
}

Case Heuristic::twoAlgo(const vector<Coord> &up, const vector<Coord> &down, bool friendly)
{
    Case success = TWO_FRIENDLY;
    Case blocked = TWO_FRIENDLY_BLOCKED;
    PIECE us = _us;
    PIECE them = _them;

    if (!friendly) {
        success = TWO_ENEMY;
        blocked = TWO_ENEMY_BLOCKED;
        us = _them;
        them = _us;
    }

    if (up.size() >= 2 && at(up[0]) == us && at(up[1]) == us) {
        if (up.size() >= 3 && at(up[2]) != them && !down.empty() && at(down[0]) != them)
            return success;
        return blocked;
    }

    if (up.size() >= 2 && !down.empty() &&
        at(up[0]) != them && at(up[1]) == us && at(down[0]) == us) {
        if (up.size() >= 3 && at(up[2]) != them && down.size() >= 2 && at(down[1]) != them)
            return success;
        return blocked;
    }

    if (!up.empty() && !down.empty()
        && at(up[0]) == us && at(down[0]) == us) {
        if (up.size() >= 2 && at(up[1]) != them && down.size() >= 2 && at(down[1]) != them)
            return success;
        return blocked;
    }

    if (up.size() >= 3 && at(up[1]) == us && at(up[0]) != them && at(up[2]) == us) {
        if (up.size() >= 4 && at(up[3]) != them && !down.empty() && at(down[0]) != them)
            return success;
        return blocked;
    }

    if (up.size() >= 3 && at(up[0]) == us && at(up[1]) != them && at(up[2]) == us) {
        if (up.size() >= 4 && at(up[3]) != them && !down.empty() && at(down[0]) != them)
            return success;
        return blocked;
    }
    return NONE;
}

Case Heuristic::oneAlgo(const vector<Coord> &up, const vector<Coord> &down, bool friendly)
{
    Case success = ONE_FRIENDLY;
    Case blocked = ONE_FRIENDLY_BLOCKED;
    PIECE us = _us;
    PIECE them = _them;

    if (!friendly) {
        success = ONE_ENEMY;
        blocked = ONE_ENEMY_BLOCKED;
        us = _them;
        them = _us;
    }

    if (up.size() > 1 && at(up[0]) == us) {
        if (at(up[1]) != them && at(down[0]) != them)
            return success;
        else
            return blocked;
    }
    return NONE;
}


int Heuristic::at(Coord node)
{
    return board[node.x][node.y];
}