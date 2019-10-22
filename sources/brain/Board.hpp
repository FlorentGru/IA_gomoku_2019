#include <vector>
#define BOARD_SIZE 20

using namespace std;

enum PIECE
{
	NONE,
	BLACK,
	WHITE,
};

class Board 
{
public:
	void start(int size);
	const vector<vector<PIECE>>& add(int x, int y, PIECE piece);
	const vector<vector<PIECE>>& get();
private:
	vector<vector<PIECE>> board;
};