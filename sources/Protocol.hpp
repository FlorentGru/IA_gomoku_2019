#include <string>
#include <vector>

enum Command
{
    UNKNOWN,
    START,
    BEGIN,
    TURN,
    BOARD,
    END
};

struct BoardArg
{
	int x;
	int y;
	int player;
};

class Protocol
{
public:
    std::string getNextCommand();
    Command whichCommand(const std::string &command);
	int getStartArg(const std::string& command);
	const std::pair<int, int> &getTurnArg(const std::string &command);
	const BoardArg getBoardArg(const std::string& command);

	int unknown();
	int answer(const std::string& rep);
private:
	const std::vector<std::string> split(const std::string&, char delimiter);
};