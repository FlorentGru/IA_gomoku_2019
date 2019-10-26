#ifndef _HEURISTIC_HPP_
#define _HEURISTIC_HPP_

#include "Board.hpp"
#include <map>
#include <vector>

#define FRIENDLY true
#define ENEMY false

#define ATTACK true
#define DEFENCE false

using namespace std;

enum Case 
{
    NONE,
	ONE_FRIENDLY,	ONE_FRIENDLY_BLOCKED,
	ONE_ENEMY,		ONE_ENEMY_BLOCKED,
	TWO_FRIENDLY,	TWO_FRIENDLY_BLOCKED,
	TWO_ENEMY,		TWO_ENEMY_BLOCKED,
	THREE_FRIENDLY, THREE_FRIENDLY_BLOCKED,
	THREE_ENEMY,	THREE_ENEMY_BLOCKED,
	FOUR_FRIENDLY,
	FOUR_ENEMY
};

class Heuristic
{
public:
    explicit Heuristic(const array<array<int, BOARD_SIZE>, BOARD_SIZE> &board);
	int getRank(Case event);

    Case isFour(const Axis &axis);
    Case isFourFriendly(const Axis &axis);
    Case isFourEnemy(const Axis &axis);
    Case fourAlgo(const vector<Coord> &up, const vector<Coord> &down, bool friendly);

    Case isThree(const Axis &axis);
    Case isThreeFriendly(const Axis &axis);
    Case isThreeEnemy(const Axis &axis);
    Case threeFriendlyAlgo(const vector<Coord> &up, const vector<Coord> &down);
    Case threeEnemyAlgo(const vector<Coord> &up, const vector<Coord> &down);

    Case isOne(const Axis &axis);
    Case isOneFriendly(const Axis &axis);
    Case isOneEnemy(const Axis &axis);
    Case oneAlgo(const vector<Coord> &up, const vector<Coord> &down, bool friendly);

	void setPlayers(PIECE us, PIECE them);
private:
    int at(Coord node);

    const array<array<int, BOARD_SIZE>, BOARD_SIZE> &board;

    PIECE _us;
    PIECE _them;

    bool mode;
    void setAttackMode();
    void setDefenceMode();

    std::map<Case, int> ranks = { {NONE, 0},
		{ONE_FRIENDLY, 5},		{ONE_FRIENDLY_BLOCKED, 2},
		{ONE_ENEMY, 6},			{ONE_ENEMY_BLOCKED, 3},
		{TWO_FRIENDLY, 10},		{TWO_FRIENDLY_BLOCKED, 5},
		{TWO_ENEMY, 15},		    {TWO_ENEMY_BLOCKED, 6},
		{THREE_FRIENDLY, 100},	{THREE_FRIENDLY_BLOCKED, 10},
		{THREE_ENEMY, 50},		{THREE_ENEMY_BLOCKED, 15},
		{FOUR_FRIENDLY, 1000},
		{FOUR_ENEMY, 500}
	};

};

#endif // !_HEURISTIC_HPP_